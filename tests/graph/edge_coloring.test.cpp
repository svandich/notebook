#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/graph/edge_coloring.h"

int main() {
  mt19937 gen(29);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,3000) {
    int n = rnd(2, 30);
    double p = rnd(1, 100) / 100.0;
    vec<pii> eds;
    rep(u,0,n) rep(v,u+1,n) if (gen() % 1000 < p * 1000) eds.pb({u, v});
    if (eds.empty()) continue;
    shuffle(all(eds), gen);
    vi deg(n);
    for (auto [u, v] : eds) deg[u]++, deg[v]++;
    int D = *max_element(all(deg));
    vi col = edgeColoring(n, eds);
    assert(sz(col) == sz(eds));
    vec<set<int>> seen(n);
    rep(i,0,sz(eds)) {
      assert(0 <= col[i] && col[i] <= D);
      for (int v : eds[i]) assert(seen[v].insert(col[i]).second);
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
