#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C"
#include "../../lib/template.h"
#include "../../lib/graph/floyd_warshall.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vec<vec<ll>> d(n, vec<ll>(n, inf));
  rep(i,0,m) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    d[a][b] = min(d[a][b], w);
  }
  floydWarshall(d);
  rep(i,0,n) if (d[i][i] < 0) {
    cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  rep(i,0,n) rep(j,0,n) {
    if (d[i][j] == inf) cout << "INF";
    else cout << d[i][j];
    cout << (j + 1 < n ? ' ' : '\n');
  }
}
