#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/hill_climbing.h"

int main() {
  mt19937 gen(47);
  uniform_real_distribution<double> U(-1000, 1000);
  rep(it,0,100) {
    double cx = U(gen), cy = U(gen), k = abs(U(gen)) / 100 + 1;
    // convex quadratic with minimum k at (cx, cy)
    auto f = [&](P p) {
      double dx = p[0] - cx, dy = p[1] - cy;
      return dx * dx + 3 * dy * dy + dx * dy + k;
    };
    auto [v, p] = hillClimb({U(gen), U(gen)}, f);
    assert(abs(v - k) < 1e-6);
    assert(abs(p[0] - cx) < 1e-4 && abs(p[1] - cy) < 1e-4);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
