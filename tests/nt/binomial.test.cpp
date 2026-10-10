#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_D"
#include "../../lib/template.h"
#include "../../lib/nt/binomial.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  initFact();
  // n identical balls into k distinct boxes: stars and bars
  cout << ncr(n + k - 1, n) << "\n";
}
