#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"
#include "../../lib/template.h"
#include "../../lib/graph/dijkstra.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, r;
  cin >> n >> m >> r;
  vec<vec<pair<int, ll>>> g(n);
  rep(i,0,m) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    g[a].pb({b, w});
  }
  for (ll d : dijkstra(g, r)) {
    if (d == inf) cout << "INF\n";
    else cout << d << "\n";
  }
}
