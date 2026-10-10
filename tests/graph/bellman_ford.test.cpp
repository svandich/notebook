#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B"
#include "../../lib/template.h"
#include "../../lib/graph/bellman_ford.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m, r;
  cin >> n >> m >> r;
  vec<Ed> eds(m);
  for (auto &e : eds) cin >> e.a >> e.b >> e.w;
  vec<Node> nodes(n);
  bellmanFord(nodes, eds, r);
  for (auto &v : nodes) if (v.dist == -inf) {
    cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  for (auto &v : nodes) {
    if (v.dist == inf) cout << "INF\n";
    else cout << v.dist << "\n";
  }
}
