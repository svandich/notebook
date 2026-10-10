#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/nt/crt.h"

int main() {
  mt19937 gen(31);
  auto rnd = [&](ll l, ll r) { return ll(gen() % (r - l + 1)) + l; };
  rep(it,0,200000) {
    ll m = rnd(1, 60), n = rnd(1, 60), a = rnd(0, m - 1), b = rnd(0, n - 1);
    if (it % 2) m = rnd(1, 1e9), n = rnd(1, 1e9), a = rnd(0, m - 1), b = rnd(0, n - 1);
    ll g = gcd(m, n), l = m / g * n;
    if ((a - b) % g) continue;
    ll x = crt(a, m, b, n);
    assert(0 <= x && x < l && x % m == a && x % n == b);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
