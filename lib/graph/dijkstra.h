#include "../template.h"
/* -
name = "Dijkstra"
[info]
description = "Shortest paths from $s$ with non-negative weights. `g[u]` holds pairs `{v, w}`. Unreachable nodes get `inf`."
time = "$O((V + E) log V)$"
warning = "not tested, writen by Claude"
- */
const ll inf = LLONG_MAX;
vec<ll> dijkstra(const vec<vec<pair<int, ll>>>& g, int s) {
  vec<ll> d(sz(g), inf);
  priority_queue<pair<ll, int>, vec<pair<ll, int>>, greater<>> pq;
  pq.push({d[s] = 0, s});
  while (!pq.empty()) {
    auto [du, u] = pq.top(); pq.pop();
    if (du > d[u]) continue;
    for (auto [v, w] : g[u])
      if (du + w < d[v]) pq.push({d[v] = du + w, v});
  }
  return d;
}
