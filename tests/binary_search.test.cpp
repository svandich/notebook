#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../lib/template.h"

int main() {
  // the snippet finds the first x in [lo, hi) with x >= 0
  rep(lo,-20,20) rep(hi,max(lo,0)+1,21) {
    ll L = lo, H = hi;
    {
      ll lo = L, hi = H;
#include "../lib/binary_search.h"
      assert(res == clamp(0LL, lo, hi));
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
