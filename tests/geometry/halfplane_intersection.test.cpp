#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_C"
#define ERROR 1e-5
#include "../../lib/template.h"
#include "../../lib/geometry/halfplane_intersection.h"
#include "../../lib/geometry/polygon_area.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vec<P> g(n);
  for (auto &p : g) cin >> p.x >> p.y;
  int q;
  cin >> q;
  cout << fixed << setprecision(8);
  while (q--) {
    P a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    vec<Line> v;
    rep(i,0,n) v.pb(Line(g[i], g[(i + 1) % n]));
    v.pb(Line(a, b));
    vec<P> res = halfPlaneIntersection(v);
    cout << (sz(res) < 3 ? 0.0 : polygonArea2(res) / 2) << "\n";
  }
}
