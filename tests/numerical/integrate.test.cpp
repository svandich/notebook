#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/integrate.h"

int main() {
  const double pi = acos(-1.0);
  assert(abs(quad(0, pi, [](double x) { return sin(x); }) - 2) < 1e-9);
  assert(abs(quad(0, 1, [](double x) { return exp(x); }) - (exp(1) - 1)) < 1e-9);
  assert(abs(quad(-1, 1, [](double x) { return sqrt(1 - x * x); }) - pi / 2) < 1e-4);
  mt19937 gen(53);
  uniform_real_distribution<double> U(-5, 5);
  rep(it,0,1000) {
    // Simpson's rule is exact for cubics
    double c[4], a = U(gen), b = U(gen);
    for (double &x : c) x = U(gen);
    auto f = [&](double x) { return ((c[3] * x + c[2]) * x + c[1]) * x + c[0]; };
    auto F = [&](double x) {
      return (((c[3] / 4 * x + c[2] / 3) * x + c[1] / 2) * x + c[0]) * x;
    };
    assert(abs(quad(a, b, f) - (F(b) - F(a))) < 1e-9);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
