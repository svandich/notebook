#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/various/fast_knapsack.h"

int main() {
  mt19937 gen(97);
  rep(it,0,20000) {
    int n = gen() % 12 + 1, mx = gen() % 30 + 1;
    vi w(n);
    for (int &x : w) x = gen() % (mx + 1);
    int t = gen() % (mx * n + 5);
    bitset<1024> can;
    can[0] = 1;
    for (int x : w) can |= can << x;
    int want = t;
    while (!can[want]) want--;
    assert(knapsack(w, t) == want);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
