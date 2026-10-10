#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/polygon_center.h"

bool near(P a, P b) { return (a - b).dist() < 1e-7; }

int main() {
  mt19937 gen(17);
  uniform_real_distribution<double> U(-100, 100);
  rep(it,0,10000) {
    // triangle: average of its vertices, in either orientation
    vec<P> t = {P(U(gen), U(gen)), P(U(gen), U(gen)), P(U(gen), U(gen))};
    if (abs(t[0].cross(t[1], t[2])) < 1) continue;
    P g = (t[0] + t[1] + t[2]) / 3;
    assert(near(polygonCenter(t), g));
    reverse(all(t));
    assert(near(polygonCenter(t), g));
  }
  rep(it,0,10000) {
    // L shape = rectangle [x0,x2]x[y0,y1] + rectangle [x0,x1]x[y1,y2]
    double x0 = U(gen), y0 = U(gen);
    double x1 = x0 + abs(U(gen)) + 1, x2 = x1 + abs(U(gen)) + 1;
    double y1 = y0 + abs(U(gen)) + 1, y2 = y1 + abs(U(gen)) + 1;
    vec<P> L = {P(x0, y0), P(x2, y0), P(x2, y1), P(x1, y1), P(x1, y2), P(x0, y2)};
    double a1 = (x2 - x0) * (y1 - y0), a2 = (x1 - x0) * (y2 - y1);
    P c1((x0 + x2) / 2, (y0 + y1) / 2), c2((x0 + x1) / 2, (y1 + y2) / 2);
    assert(near(polygonCenter(L), (c1 * a1 + c2 * a2) / (a1 + a2)));
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
