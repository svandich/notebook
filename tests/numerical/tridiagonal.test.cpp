#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/tridiagonal.h"

int main() {
  mt19937 gen(79);
  uniform_real_distribution<double> U(-10, 10);
  rep(it,0,20000) {
    int n = gen() % 10 + 1;
    // row i: sub[i-1] x[i-1] + diag[i] x[i] + super[i] x[i+1] = b[i]
    vec<T> diag(n), super(max(n - 1, 0)), sub(max(n - 1, 0)), x(n), b(n);
    for (auto &v : diag) v = U(gen);
    for (auto &v : super) v = U(gen);
    for (auto &v : sub) v = U(gen);
    // sometimes force zeros on the diagonal to exercise pivoting
    rep(i,0,n-1) if (gen() % 4 == 0) diag[i] = 0;
    for (auto &v : x) v = U(gen);
    rep(i,0,n) {
      b[i] = diag[i] * x[i];
      if (i + 1 < n) b[i] += super[i] * x[i + 1];
      if (i) b[i] += sub[i - 1] * x[i - 1];
    }
    vec<T> got = tridiagonal(diag, super, sub, b);
    rep(i,0,n) {
      double r = diag[i] * got[i] - b[i];
      if (i + 1 < n) r += super[i] * got[i + 1];
      if (i) r += sub[i - 1] * got[i - 1];
      assert(abs(r) < 1e-6);
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
