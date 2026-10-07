#include "../template.h"
/* -
name = "Grid BFS"
[info]
description = "Distances from $(r, c)$ in a grid where `'#'` is a wall. Unreachable cells get $-1$. For 0-1 BFS use a `deque`: `push_front` on weight 0, `push_back` on weight 1."
time = "$O(R C)$"
warning = "not tested, writen by Claude"
- */
const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
vec<vi> gridBfs(const vec<string>& g, int sr, int sc) {
  int R = sz(g), C = sz(g[0]);
  vec<vi> d(R, vi(C, -1));
  queue<pii> q;
  d[sr][sc] = 0, q.push({sr, sc});
  while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    rep(k,0,4) {
      int nr = r + dr[k], nc = c + dc[k];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (g[nr][nc] == '#' || d[nr][nc] != -1) continue;
      d[nr][nc] = d[r][c] + 1, q.push({nr, nc});
    }
  }
  return d;
}
