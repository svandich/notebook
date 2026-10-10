#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/nt/continued_fractions.h"

int main() {
  mt19937 gen(37);
  uniform_real_distribution<double> U(0, 3);
  rep(it,0,100000) {
    ll N = gen() % 200 + 1;
    double x = U(gen);
    if (it % 4 == 0) x = double(gen() % 50) / double(gen() % 50 + 1);
    auto [p, q] = approximate(x, N);
    assert(0 <= p && p <= N && 1 <= q && q <= N);
    double got = abs((double)p / (double)q - x), best = 1e18;
    rep(Q,1,N+1) for (ll P : {(ll)floor(x * Q), (ll)ceil(x * Q)})
      if (0 <= P && P <= N) best = min(best, abs((double)P / Q - x));
    assert(got <= best + 1e-12);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
