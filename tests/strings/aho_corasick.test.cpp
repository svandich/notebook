#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"
#include "../../lib/template.h"
#include "../../lib/strings/aho_corasick.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vec<string> s(n);
  for (auto &x : s) {
    cin >> x;
    for (char &c : x) c = char(toupper(c));
  }
  AhoCorasick ac(s);
  // nodes are created in the order the problem asks for; the last one is
  // the helper node behind the root
  int cnt = sz(ac.N) - 1;
  vi par(cnt), node(n);
  rep(i,0,n) {
    int v = 0;
    for (char c : s[i]) {
      int u = ac.N[v].next[c - 'A'];
      par[u] = v, v = u;
    }
    node[i] = v;
  }
  cout << cnt << "\n";
  rep(v,1,cnt) cout << par[v] << " " << ac.N[v].back << "\n";
  rep(i,0,n) cout << node[i] << " \n"[i == n - 1];
}
