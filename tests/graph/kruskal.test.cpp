#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "../../lib/template.h"
#include "../../lib/graph/kruskal.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vec<Edge> eds(m);
  map<Edge, vi> id;
  rep(i,0,m) {
    auto &[w, a, b] = eds[i];
    cin >> a >> b >> w;
    id[eds[i]].pb(i);
  }
  vec<Edge> mst;
  cout << kruskal(n, eds, mst) << "\n";
  for (auto &e : mst) {
    cout << id[e].back() << " ";
    id[e].pop_back();
  }
  cout << "\n";
}
