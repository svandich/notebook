#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/minkowski.h"

int main() {
  mt19937 gen(3);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  auto randomHull = [&]() {
    vec<P> v(rnd(1, 10));
    for (auto &p : v) p = P(rnd(-20, 20), rnd(-20, 20));
    return convexHull(v);
  };
  rep(it,0,50000) {
    vec<P> p = randomHull(), q = randomHull();
    vec<P> sums;
    for (P a : p) for (P b : q) sums.pb(a + b);
    assert(minkowskiSum(p, q) == convexHull(sums));
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
