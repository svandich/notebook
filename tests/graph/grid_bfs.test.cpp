#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0558"
#include "../../lib/template.h"
#include "../../lib/graph/grid_bfs.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int h, w, n;
  cin >> h >> w >> n;
  vec<string> g(h);
  vec<pii> at(n + 1);
  rep(r,0,h) {
    cin >> g[r];
    rep(c,0,w) {
      char &ch = g[r][c];
      if (ch == 'X') ch = '#';
      else if (ch == 'S') at[0] = {r, c};
      else if (isdigit(ch)) at[ch - '0'] = {r, c};
    }
  }
  int ans = 0;
  rep(i,0,n) {
    auto d = gridBfs(g, at[i][0], at[i][1]);
    ans += d[at[i + 1][0]][at[i + 1][1]];
  }
  cout << ans << "\n";
}
