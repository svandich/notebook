#include "../template.h"
/* -
name = "Floyd-Warshall"
[info]
description = "All-pairs shortest paths. Input: `m[i][j]` is the edge weight or `inf`. Afterwards `m[i][j]` is `-inf` if some $i -> j$ path goes through a negative cycle."
time = "$O(V^3)$"
warning = "not tested, writen by Claude"
- */
const ll inf = 1LL << 62;
void floydWarshall(vec<vec<ll>>& m) {
  int n = sz(m);
  rep(i,0,n) m[i][i] = min(m[i][i], 0LL);
  rep(k,0,n) rep(i,0,n) rep(j,0,n)
    if (m[i][k] != inf && m[k][j] != inf)
      m[i][j] = min(m[i][j], max(m[i][k] + m[k][j], -inf));
  rep(k,0,n) if (m[k][k] < 0) rep(i,0,n) rep(j,0,n)
    if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}
