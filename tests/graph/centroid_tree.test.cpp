#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../lib/template.h"
#include "../../lib/graph/centroid_tree.h"
#include "../../lib/numerical/ntt.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vec<vi> g(n);
  rep(i,0,n-1) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b), g[b].pb(a);
  }
  vi par = centroidTree(g);
  vec<vi> ch(n);
  int root = -1;
  rep(v,0,n) {
    if (par[v] == -1) root = v;
    else ch[par[v]].pb(v);
  }
  vi lvl(n);
  vi order = {root};
  rep(i,0,sz(order)) for (int c : ch[order[i]])
    lvl[c] = lvl[order[i]] + 1, order.pb(c);
  assert(*max_element(all(lvl)) <= __lg(n) + 1);

  // depth counts of the part of the component of c hanging from y
  auto depths = [&](int c, int y) {
    vec<ll> cnt;
    vec<array<int, 3>> st = {{y, c, 1}};
    while (sz(st)) {
      auto [v, p, d] = st.back();
      st.pop_back();
      if (sz(cnt) <= d) cnt.resize(d + 1);
      cnt[d]++;
      for (int u : g[v]) if (u != p && lvl[u] > lvl[c]) st.pb({u, v, d + 1});
    }
    return cnt;
  };
  vec<ll> ans(n);
  rep(c,0,n) {
    vec<ll> cnt = {1};
    vec<vec<ll>> parts;
    for (int y : g[c]) if (lvl[y] > lvl[c]) {
      parts.pb(depths(c, y));
      if (sz(cnt) < sz(parts.back())) cnt.resize(sz(parts.back()));
      rep(d,0,sz(parts.back())) cnt[d] += parts.back()[d];
    }
    ll comp = accumulate(all(cnt), 0LL);
    vec<ll> tot = convBig(cnt, cnt);
    rep(d,1,sz(tot)) ans[d] += tot[d];
    for (auto &p : parts) {
      assert(2 * accumulate(all(p), 0LL) <= comp);
      vec<ll> sub = convBig(p, p);
      rep(d,1,sz(sub)) ans[d] -= sub[d];
    }
  }
  rep(d,1,n) cout << ans[d] / 2 << " \n"[d == n - 1];
  if (n == 1) cout << "\n";
}
