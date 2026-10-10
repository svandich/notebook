#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/point_3d.h"
#include "../../lib/geometry/polyhedron_volume.h"
using P = Point3D<double>;
struct Tri { int a, b, c; };

int main() {
  mt19937 gen(13);
  uniform_real_distribution<double> U(-10, 10);
  // box [0,w]x[0,h]x[0,d] shifted by o, split into outward triangles
  rep(it,0,1000) {
    double w = abs(U(gen)) + 0.1, h = abs(U(gen)) + 0.1, d = abs(U(gen)) + 0.1;
    P o(U(gen), U(gen), U(gen));
    vec<P> p;
    rep(i,0,8) p.pb(o + P(i & 1 ? w : 0, i & 2 ? h : 0, i & 4 ? d : 0));
    vec<Tri> faces = {
      {0, 2, 1}, {1, 2, 3}, {4, 5, 6}, {5, 7, 6}, // z = 0, z = d
      {0, 1, 4}, {1, 5, 4}, {2, 6, 3}, {3, 6, 7}, // y = 0, y = h
      {0, 4, 2}, {2, 4, 6}, {1, 3, 5}, {3, 7, 5}, // x = 0, x = w
    };
    assert(abs(signedPolyVolume(p, faces) - w * h * d) < 1e-9);
  }
  // tetrahedra: |det| / 6
  rep(it,0,1000) {
    vec<P> p(4);
    for (auto &x : p) x = P(U(gen), U(gen), U(gen));
    double det = (p[1] - p[0]).cross(p[2] - p[0]).dot(p[3] - p[0]);
    if (abs(det) < 1e-3) continue;
    if (det < 0) swap(p[1], p[2]), det = -det;
    vec<Tri> faces = {{0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {1, 2, 3}};
    assert(abs(signedPolyVolume(p, faces) - det / 6) < 1e-9);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
