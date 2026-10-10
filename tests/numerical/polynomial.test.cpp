#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/polynomial.h"

int main() {
  mt19937 gen(67);
  uniform_real_distribution<double> U(-3, 3);
  rep(it,0,10000) {
    int n = gen() % 8 + 1;
    Poly p{vec<double>(n)};
    for (double &v : p.a) v = U(gen);
    double x = U(gen);
    double naive = 0, dnaive = 0;
    rep(i,0,n) naive += p.a[i] * pow(x, i);
    rep(i,1,n) dnaive += i * p.a[i] * pow(x, i - 1);
    assert(abs(p(x) - naive) < 1e-9);
    // dividing by (t - r) leaves p(t) = (t - r) q(t) + p(r)
    double r = U(gen);
    Poly q = p;
    q.divroot(r);
    assert(sz(q.a) == n - 1);
    assert(abs((x - r) * q(x) + p(r) - p(x)) < 1e-9);
    p.diff();
    assert(sz(p.a) == n - 1 && abs(p(x) - dnaive) < 1e-9);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
