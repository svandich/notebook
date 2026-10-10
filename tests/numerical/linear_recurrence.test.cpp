#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
const ll mod = 998244353;
#include "../../lib/numerical/linear_recurrence.h"

int main() {
  mt19937 gen(59);
  rep(it,0,300) {
    int n = gen() % 8 + 1;
    Poly S(n), tr(n);
    for (ll &x : S) x = gen() % mod;
    for (ll &x : tr) x = gen() % mod;
    // naive: a_i = sum tr[j] * a_(i-1-j)
    vec<ll> a = S;
    while (sz(a) < 1000) {
      ll v = 0;
      rep(j,0,n) v = (v + tr[j] * a[sz(a) - 1 - j]) % mod;
      a.pb(v);
    }
    rep(k,0,1000) assert(linearRec(S, tr, k) == a[k]);
  }
  // Fibonacci
  assert(linearRec({0, 1}, {1, 1}, 90) == 2880067194370816120LL % mod);
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
