#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/convex_hull.h"
#include "../../lib/geometry/line_hull_intersection.h"

// position of the intersection of line a-b with edge (p, q) along a -> b
double hitAt(P a, P b, P p, P q) {
  double s = (double)a.cross(b, p), t = (double)a.cross(b, q);
  double fx = p.x + (q.x - p.x) * s / (s - t);
  double fy = p.y + (q.y - p.y) * s / (s - t);
  return (fx - a.x) * (b.x - a.x) + (fy - a.y) * (b.y - a.y);
}

int main() {
  mt19937 gen(7);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,200000) {
    vec<P> pts(rnd(3, 8));
    for (auto &p : pts) p = P(rnd(-5, 5), rnd(-5, 5));
    vec<P> poly = convexHull(pts);
    int n = sz(poly);
    if (n < 3) continue;
    P a(rnd(-7, 7), rnd(-7, 7)), b(rnd(-7, 7), rnd(-7, 7));
    if (a == b) continue;
    pii res = lineHull(a, b, poly);
    vi s(n);
    rep(i,0,n) s[i] = sgn(a.cross(poly[i], b));
    bool pos = count(all(s), 1), neg = count(all(s), -1);
    int zeros = (int)count(all(s), 0);
    if (!(pos && neg)) {
      if (zeros == 0) assert(res == (pii{-1, -1}));
      else if (zeros == 1) {
        int i = int(find(all(s), 0) - s.begin());
        assert(res == (pii{i, -1}));
      } else {
        assert(zeros == 2);
        int i = 0;
        while (s[i] || s[(i + 1) % n]) i++;
        assert(res == (pii{i, i}));
      }
    } else {
      // the line crosses the interior: it enters through side res[0]
      // and leaves through side res[1]
      auto [i, j] = res;
      assert(i != j && 0 <= i && i < n && 0 <= j && j < n);
      assert(s[i] * s[(i + 1) % n] <= 0 && s[j] * s[(j + 1) % n] <= 0);
      double hi = s[i] == 0 ? (double)(poly[i] - a).dot(b - a)
                            : hitAt(a, b, poly[i], poly[(i + 1) % n]);
      double hj = s[j] == 0 ? (double)(poly[j] - a).dot(b - a)
                            : hitAt(a, b, poly[j], poly[(j + 1) % n]);
      assert(hi < hj + 1e-9);
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
