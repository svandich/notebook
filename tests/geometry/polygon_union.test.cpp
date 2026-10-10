#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/polygon_union.h"

int main() {
  mt19937 gen(19);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,20000) {
    // union of integer rectangles, compared with counting unit cells
    int n = rnd(1, 6);
    vec<vec<P>> poly;
    vec<vec<bool>> cell(8, vec<bool>(8));
    rep(i,0,n) {
      int x0 = rnd(0, 7), y0 = rnd(0, 7), x1 = rnd(x0 + 1, 8), y1 = rnd(y0 + 1, 8);
      poly.pb({P(x0, y0), P(x1, y0), P(x1, y1), P(x0, y1)});
      rep(x,x0,x1) rep(y,y0,y1) cell[x][y] = 1;
      if (rnd(0, 3) == 0) poly.pb(poly.back()); // repeated polygon
    }
    int cnt = 0;
    rep(x,0,8) rep(y,0,8) cnt += cell[x][y];
    assert(abs(polyUnion(poly) - cnt) < 1e-6);
  }
  // a single non-convex polygon (U shape, area 7)
  vec<vec<P>> u = {{P(0, 0), P(3, 0), P(3, 3), P(2, 3), P(2, 1), P(1, 1), P(1, 3), P(0, 3)}};
  assert(abs(polyUnion(u) - 7) < 1e-9);
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
