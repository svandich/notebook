#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_H"
#define ERROR 1e-5
#include "../../lib/template.h"
#include "../../lib/geometry/circle_polygon_intersection.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  double r;
  cin >> n >> r;
  vec<P> ps(n);
  for (auto &p : ps) cin >> p.x >> p.y;
  cout << fixed << setprecision(10) << circlePoly(P(0, 0), r, ps) << "\n";
}
