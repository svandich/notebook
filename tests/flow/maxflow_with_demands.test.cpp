#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/flow/dinic.h"
#include "../../lib/flow/maxflow_with_demands.h"

// Brute force: try every integer flow on every edge and check that it is a
// valid flow from s to t (any non-negative amount).
bool brute(int n, int s, int t, vec<array<int, 4>>& eds) {
  int m = sz(eds);
  vi f(m);
  for (int i = 0; i < m; i++) f[i] = eds[i][3];
  while (true) {
    vi bal(n);
    rep(i,0,m) bal[eds[i][0]] -= f[i], bal[eds[i][1]] += f[i];
    bool ok = true;
    rep(v,0,n) if (v != s && v != t && bal[v]) ok = false;
    if (ok && bal[t] >= 0) return true;
    int i = 0;
    while (i < m && f[i] == eds[i][2]) f[i] = eds[i][3], i++;
    if (i == m) return false;
    f[i]++;
  }
}

int main() {
  mt19937 gen(12345);
  rep(it,0,3000) {
    int n = gen() % 4 + 2, m = gen() % 6 + 1;
    int s = 0, t = n - 1;
    vec<array<int, 4>> eds; // u, v, cap, demand
    rep(i,0,m) {
      int u = gen() % n, v = gen() % n;
      if (u == v) continue;
      int cap = gen() % 3, dem = gen() % (cap + 1);
      if (gen() % 3) dem = 0;
      eds.pb({u, v, cap, dem});
    }
    FlowDemands<Dinic> fd(n);
    ll need = 0;
    for (auto [u, v, cap, dem] : eds) fd.addEdge(u, v, cap, dem), need += dem;
    bool feasible = fd.calc(s, t) == need;
    assert(feasible == brute(n, s, t, eds));
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
