#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/graph/weighted_matroid_intersection.h"

// Partition matroid: at most one chosen edge per endpoint on one side.
struct Partition {
  vi side;
  vec<bool> used;
  Partition(vi side, int n) : side(side), used(n) {}
  void build(const vi& I) {
    fill(all(used), false);
    for (int e : I) used[side[e]] = true;
  }
  bool oracle(int add) { return !used[side[add]]; }
  bool oracle(int add, int rem) {
    return !used[side[add]] || side[add] == side[rem];
  }
};

// Minimum weight maximum bipartite matching, compared with brute force.
int main() {
  mt19937 gen(23);
  auto rnd = [&](int lo, int hi) { return int(gen() % (hi - lo + 1)) + lo; };
  rep(it,0,3000) {
    int x = rnd(1, 4), y = rnd(1, 4), m = rnd(1, 10);
    vi l(m), r(m);
    vec<ll> w(m);
    rep(i,0,m) l[i] = rnd(0, x - 1), r[i] = rnd(0, y - 1), w[i] = rnd(-20, 20);
    pair<int, ll> best = {0, 0}; // (-size, weight)
    rep(mask,0,1 << m) {
      int cl = 0, cr = 0, cnt = 0;
      ll s = 0;
      bool ok = true;
      rep(i,0,m) if (mask >> i & 1) {
        if ((cl >> l[i] & 1) || (cr >> r[i] & 1)) ok = false;
        cl |= 1 << l[i], cr |= 1 << r[i], cnt++, s += w[i];
      }
      if (ok) best = min(best, make_pair(-cnt, s));
    }
    vi I = weightedMatroidInter(m, w, Partition(l, x), Partition(r, y));
    set<int> sl, sr;
    ll s = 0;
    for (int e : I) sl.insert(l[e]), sr.insert(r[e]), s += w[e];
    assert(sz(sl) == sz(I) && sz(sr) == sz(I));
    assert(make_pair(-sz(I), s) == best);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
