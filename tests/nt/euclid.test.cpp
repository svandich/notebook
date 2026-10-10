#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"
#include "../../lib/template.h"
#include "../../lib/nt/euclid.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll a, b, x, y;
  cin >> a >> b;
  euclid(a, b, x, y);
  cout << x << " " << y << "\n";
}
