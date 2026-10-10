#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/nt/frac_binary_search.h"

int main() {
  mt19937 gen(41);
  rep(it,0,20000) {
    ll N = gen() % 100 + 1, b = gen() % 1000 + 1, a = gen() % (b + 1);
    // smallest p/q in [0, 1] with p/q >= a/b
    auto f = [&](Frac x) { return x.p * b >= a * x.q; };
    Frac r = fracBS(f, N);
    assert(0 <= r.p && r.p <= N && 1 <= r.q && r.q <= N && f(r));
    rep(q,1,N+1) rep(p,0,q+1) if (f({p, q})) assert(r.p * q <= p * r.q);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
