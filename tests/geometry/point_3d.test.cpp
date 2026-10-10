#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/point_3d.h"
using P = Point3D<double>;

bool near(P a, P b) { return (a - b).dist() < 1e-9; }

int main() {
  const double pi = acos(-1.0);
  P x(1, 0, 0), y(0, 1, 0), z(0, 0, 1);
  assert(near(x.cross(y), z) && near(y.cross(z), x) && near(z.cross(x), y));
  assert(near(x.rotate(pi / 2, z), y));
  assert(near(y.rotate(pi / 2, x), z));
  assert(abs(y.phi() - pi / 2) < 1e-12 && abs(z.theta()) < 1e-12);
  assert(abs(x.theta() - pi / 2) < 1e-12);

  mt19937 gen(5);
  uniform_real_distribution<double> U(-10, 10);
  rep(it,0,10000) {
    P a(U(gen), U(gen), U(gen)), b(U(gen), U(gen), U(gen));
    P c = a.cross(b);
    assert(abs(c.dot(a)) < 1e-9 && abs(c.dot(b)) < 1e-9);
    assert(abs(a.unit().dist() - 1) < 1e-12);
    assert(abs(a.normal(b).dist() - 1) < 1e-9);
    double ang = U(gen);
    P r = a.rotate(ang, b);
    // rotating keeps the length and the component along the axis
    assert(abs(r.dist() - a.dist()) < 1e-9);
    assert(abs(r.dot(b.unit()) - a.dot(b.unit())) < 1e-9);
    // spherical coordinates give the point back
    double R = a.dist(), t = a.theta(), f = a.phi();
    assert(near(P(R * sin(t) * cos(f), R * sin(t) * sin(f), R * cos(t)), a));
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
