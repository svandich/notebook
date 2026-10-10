#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0009"
#include "../../lib/template.h"
#include "../../lib/nt/eratosthenes.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  vi pr = eratosthenesSieve(1'000'000);
  int n;
  while (cin >> n) cout << upper_bound(all(pr), n) - pr.begin() << "\n";
}
