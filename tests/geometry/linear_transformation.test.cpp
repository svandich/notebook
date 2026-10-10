#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#define ERROR 1e-8
#include "../../lib/template.h"
#include "../../lib/geometry/point.h"
#include "../../lib/geometry/linear_transformation.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  P a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  int q;
  cin >> q;
  cout << fixed << setprecision(10);
  P o(0, 0), e(1, 0);
  while (q--) {
    P p;
    cin >> p.x >> p.y;
    // send line a-b to the x axis, drop the y coordinate and come back
    P t = linearTransformation(a, b, o, e, p);
    P r = linearTransformation(o, e, a, b, P(t.x, 0));
    cout << r.x << " " << r.y << "\n";
  }
}
