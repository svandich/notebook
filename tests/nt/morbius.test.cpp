#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/nt/morbius.h"

int main() {
  calculateMu();
  rep(n,1,100000) {
    int x = n, primes = 0;
    bool squarefree = true;
    for (int p = 2; p * p <= x; p++) if (x % p == 0) {
      x /= p, primes++;
      if (x % p == 0) squarefree = false;
      while (x % p == 0) x /= p;
    }
    if (x > 1) primes++;
    assert(mu[n] == (squarefree ? (primes % 2 ? -1 : 1) : 0));
  }
  // sum of mu over the divisors of n is [n == 1]
  vi s(L);
  rep(d,1,L) for (int m = d; m < L; m += d) s[m] += mu[d];
  rep(n,1,L) assert(s[n] == (n == 1));
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
