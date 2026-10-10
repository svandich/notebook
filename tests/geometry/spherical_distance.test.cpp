#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0177"
#include "../../lib/template.h"
#include "../../lib/geometry/spherical_distance.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  const double pi = acos(-1.0);
  double a, b, c, d;
  while (cin >> a >> b >> c >> d && !(a == -1 && b == -1 && c == -1 && d == -1)) {
    // latitude -> zenith angle, longitude -> azimuthal angle
    double t1 = (90 - a) * pi / 180, f1 = b * pi / 180;
    double t2 = (90 - c) * pi / 180, f2 = d * pi / 180;
    cout << llround(sphericalDistance(f1, t1, f2, t2, 6378.1)) << "\n";
  }
}
