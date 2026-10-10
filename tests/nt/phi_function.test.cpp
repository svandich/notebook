#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2286"
#include "../../lib/template.h"
#include "../../lib/nt/phi_function.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  calculatePhi();
  const int N = 1'000'001;
  // size of the Farey sequence F_n is 1 + phi(1) + ... + phi(n)
  vec<ll> farey(N, 1);
  rep(i,1,N) farey[i] = farey[i - 1] + phi[i];
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << farey[n] << "\n";
  }
}
