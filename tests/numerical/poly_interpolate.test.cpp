#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/poly_interpolate.h"

int main() {
  mt19937 gen(61);
  rep(it,0,10000) {
    int n = gen() % 8 + 1;
    vd c(n), x(n), y(n);
    for (double &v : c) v = int(gen() % 21) - 10;
    // distinct sample points
    vi xs(21);
    iota(all(xs), -10);
    shuffle(all(xs), gen);
    rep(i,0,n) {
      x[i] = xs[i];
      for (int j = n; j--;) y[i] = y[i] * x[i] + c[j];
    }
    vd res = interpolate(x, y, n);
    rep(i,0,n) assert(abs(res[i] - c[i]) < 1e-6);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
