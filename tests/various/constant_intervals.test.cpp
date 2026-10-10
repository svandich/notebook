#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/various/constant_intervals.h"

int main() {
  mt19937 gen(89);
  rep(it,0,20000) {
    int n = gen() % 50;
    vi v(n);
    rep(i,0,n) v[i] = (i ? v[i - 1] : 0) + (gen() % 4 == 0);
    vec<array<int, 3>> got, want;
    constantIntervals(0, n, [&](int x) { return v[x]; },
      [&](int lo, int hi, int val) { got.pb({lo, hi, val}); });
    rep(i,0,n) {
      if (i && v[i] == v[i - 1]) want.back()[1] = i + 1;
      else want.pb({i, i + 1, v[i]});
    }
    assert(got == want);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
