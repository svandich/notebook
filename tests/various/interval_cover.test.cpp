#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/various/interval_cover.h"

int main() {
  mt19937 gen(103);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,20000) {
    int n = rnd(0, 8);
    vec<pii> I(n);
    vec<pair<int, int>> J(n);
    rep(i,0,n) {
      int l = rnd(0, 15), r = rnd(l, 16);
      I[i] = {l, r}, J[i] = {l, r};
    }
    int gl = rnd(0, 15), gr = rnd(gl + 1, 16);
    // brute force: smallest subset covering [gl, gr)
    int best = INT_MAX;
    rep(mask,0,1 << n) {
      int cur = gl;
      bool grew = true;
      while (cur < gr && grew) {
        grew = false;
        rep(i,0,n) if (mask >> i & 1 && I[i][0] <= cur && cur < I[i][1])
          cur = I[i][1], grew = true;
      }
      if (cur >= gr) best = min(best, __builtin_popcount(mask));
    }
    vi got = cover(make_pair(gl, gr), J);
    if (best == INT_MAX) {
      assert(got.empty());
      continue;
    }
    assert(sz(got) == best);
    vec<bool> covered(16);
    for (int i : got) rep(x,I[i][0],I[i][1]) covered[x] = true;
    rep(x,gl,gr) assert(covered[x]);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
