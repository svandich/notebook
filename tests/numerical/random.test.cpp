#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/random.h"

int main() {
  rep(it,0,1000) {
    ll l = rnd(-1e18, 1e18), r = rnd(l, (ll)1e18);
    ll x = rnd(l, r);
    assert(l <= x && x <= r);
  }
  // every value of a small range shows up, roughly uniformly
  vi cnt(10);
  rep(it,0,100000) cnt[rnd(0, 9)]++;
  for (int c : cnt) assert(9000 < c && c < 11000);
  assert(rnd(5, 5) == 5);
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
