#include "../template.h"
#include "../ds/uf.h"
/* -
name = "Kruskal"
[info]
description = "Minimum spanning forest. Edges are `{w, a, b}`. Returns the total weight and pushes the chosen edges to `mst`."
time = "$O(E log E)$"
warning = "not tested, writen by Claude"
- */
using Edge = array<ll, 3>;
ll kruskal(int n, vec<Edge> eds, vec<Edge>& mst) {
  sort(all(eds));
  UnionFind uf(n);
  ll res = 0;
  for (auto& e : eds)
    if (uf.join(e[1], e[2])) res += e[0], mst.pb(e);
  return res;
}
