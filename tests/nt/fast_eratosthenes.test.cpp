#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0009"
#include "../../lib/template.h"
#include "../../lib/nt/fast_eratosthenes.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vi pr = eratosthenes();
  rep(i,0,1000) assert(isPrime[i] == (i > 1 && all_of(pr.begin(), pr.end(),
    [&](int p) { return p * p > i || i % p; })));
  int n;
  while (cin >> n) cout << upper_bound(all(pr), n) - pr.begin() << "\n";
}
