#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/integrate_adaptive.h"

int main() {
  const double pi = acos(-1.0);
  assert(abs(quad(0, pi, [](double x) { return sin(x); }) - 2) < 1e-7);
  assert(abs(quad(0, 1, [](double x) { return exp(x); }) - (exp(1) - 1)) < 1e-7);
  assert(abs(quad(-1, 1, [](double x) { return sqrt(1 - x * x); }) - pi / 2) < 1e-6);
  assert(abs(quad(0, 1, [](double x) { return sqrt(x); }) - 2.0 / 3) < 1e-6);
  // area of the unit disk as a nested integral
  double disk = quad(-1, 1, [&](double x) {
    return quad(-1, 1, [&](double y) { return x * x + y * y <= 1 ? 1.0 : 0.0; });
  });
  assert(abs(disk - pi) < 1e-4);
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
