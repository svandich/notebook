#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_B"
#define ERROR 1e-8
#include "../../lib/template.h"
#include "../../lib/geometry/point.h"
#include "../../lib/geometry/line_distance.h"
using P = Point<double>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  P a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  int q;
  cin >> q;
  cout << fixed << setprecision(10);
  while (q--) {
    P p;
    cin >> p.x >> p.y;
    // reflect p across the line: move twice its distance along the normal
    P r = p - (b - a).normal() * (2 * lineDist(a, b, p));
    cout << r.x << " " << r.y << "\n";
  }
}
