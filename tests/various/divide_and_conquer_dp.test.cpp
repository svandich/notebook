#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
vec<vec<ll>> dp;
vec<pii> res;
#include "../../lib/various/divide_and_conquer_dp.h"

int main() {
  mt19937 gen(109);
  rep(it,0,3000) {
    // f(i, k) = c[k] + (S[i] - S[k])^2 with S increasing has monotone opt
    int n = gen() % 60 + 1;
    vec<ll> S(n), c(n);
    rep(i,1,n) S[i] = S[i - 1] + gen() % 20;
    for (ll &x : c) x = gen() % 300;
    dp.assign(n, vec<ll>(n));
    rep(i,0,n) rep(k,0,n) dp[i][k] = c[k] + (S[i] - S[k]) * (S[i] - S[k]);
    res.assign(n, {-1, -1});
    DP().solve(1, n);
    rep(i,1,n) {
      ll want = LLONG_MAX;
      rep(k,0,i) want = min(want, dp[i][k]);
      auto [k, v] = res[i];
      assert(v == want && 0 <= k && k < i && dp[i][k] == want);
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
