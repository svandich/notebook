#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"
#include "../../lib/template.h"
#include "../../lib/graph/euler_walk.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vec<vec<pii>> g(n);
    vi bal(n);
    unordered_map<ll, vi> ids;
    rep(i,0,m) {
      int u, v;
      cin >> u >> v;
      g[u].pb({v, i});
      bal[u]++, bal[v]--;
      ids[(ll)u * n + v].pb(i);
    }
    int src = 0;
    rep(v,0,n) if (sz(g[v])) src = v;
    rep(v,0,n) if (bal[v] == 1) src = v;
    vi walk = eulerWalk(g, m, src);
    if (walk.empty()) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    rep(i,0,m+1) cout << walk[i] << " \n"[i == m];
    // parallel edges are interchangeable, so take any unused one
    rep(i,0,m) {
      vi &e = ids[(ll)walk[i] * n + walk[i + 1]];
      cout << e.back() << " ";
      e.pop_back();
    }
    cout << "\n";
  }
}
