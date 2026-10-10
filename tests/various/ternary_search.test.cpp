#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/various/ternary_search.h"

int main() {
  mt19937 gen(107);
  rep(it,0,100000) {
    // strictly increasing up to the peak, then non-increasing
    int n = gen() % 40 + 1, peak = gen() % n;
    vi v(n);
    rep(i,1,peak+1) v[i] = v[i - 1] + int(gen() % 3) + 1;
    rep(i,peak+1,n) v[i] = v[i - 1] - int(gen() % 3);
    int a = gen() % n, b = gen() % n;
    if (a > b) swap(a, b);
    int want = a;
    rep(i,a,b+1) if (v[i] > v[want]) want = i;
    if (a <= peak && peak <= b) assert(want == peak);
    else if (peak < a) assert(want == a);
    assert(ternSearch(a, b, [&](int i) { return v[i]; }) == want);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
