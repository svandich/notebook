#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A"
#include "../../lib/template.h"
#include "../../lib/graph/matroid_intersection.h"

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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int x, y, m;
  cin >> x >> y >> m;
  vi l(m), r(m);
  rep(i,0,m) cin >> l[i] >> r[i];
  vi I = matroidInter(m, Partition(l, x), Partition(r, y));
  cout << sz(I) << "\n";
}
