#include "../template.h"
/* -
name = "Binomial Coefficients"
[info]
description = "Call `initFact()` once, then `ncr(n, k)` gives $binom(n, k) mod p$. `mod` must be prime and greater than `N`."
time = "$O(N)$ preprocessing, $O(1)$ per query"
warning = "not tested, writen by Claude"
- */
const ll mod = 1e9 + 7; // use const!
#include "mod_pow.h"
const int N = 1e6 + 5;
ll fact[N], inv[N];
void initFact() {
  fact[0] = 1;
  rep(i,1,N) fact[i] = fact[i-1] * i % mod;
  inv[N-1] = modpow(fact[N-1], mod - 2);
  for (int i = N - 1; i > 0; i--) inv[i-1] = inv[i] * i % mod;
}
ll ncr(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * inv[k] % mod * inv[n-k] % mod;
}
