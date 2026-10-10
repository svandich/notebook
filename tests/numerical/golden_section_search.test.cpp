#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/golden_section_search.h"

int main() {
  mt19937 gen(43);
  uniform_real_distribution<double> U(-100, 100);
  rep(it,0,10000) {
    double a = U(gen), b = U(gen), c = U(gen), k = abs(U(gen)) + 0.1;
    if (a > b) swap(a, b);
    if (b - a < 1e-3) continue;
    double x = gss(a, b, [&](double t) { return k * (t - c) * (t - c); });
    assert(abs(x - clamp(c, a, b)) < 1e-6);
    x = gss(a, b, [&](double t) { return abs(t - c); });
    assert(abs(x - clamp(c, a, b)) < 1e-6);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
