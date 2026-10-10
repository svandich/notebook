#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A"
#include "../../lib/template.h"
#include "../../lib/graph/topo_sort.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vec<vi> g(n);
  rep(i,0,m) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
  }
  vi order = topoSort(g);
  // a cycle leaves some vertices out of the order
  if (sz(order) < n) {
    cout << "1\n";
    return 0;
  }
  vi pos(n);
  rep(i,0,n) pos[order[i]] = i;
  rep(u,0,n) for (int v : g[u]) assert(pos[u] < pos[v]);
  cout << "0\n";
}
