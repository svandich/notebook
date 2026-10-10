#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C"
#include "../../lib/template.h"
#include "../../lib/geometry/point.h"
#include "../../lib/geometry/on_segment.h"
#include "../../lib/geometry/side_of.h"
using P = Point<ll>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  P a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  int q;
  cin >> q;
  while (q--) {
    P p;
    cin >> p.x >> p.y;
    ll s = sideOf(a, b, p);
    if (s > 0) cout << "COUNTER_CLOCKWISE\n";
    else if (s < 0) cout << "CLOCKWISE\n";
    else if (onSegment(a, b, p)) cout << "ON_SEGMENT\n";
    else if ((b - a).dot(p - a) < 0) cout << "ONLINE_BACK\n";
    else cout << "ONLINE_FRONT\n";
  }
}
