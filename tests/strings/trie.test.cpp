#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_C"
#include "../../lib/template.h"
#include "../../lib/strings/trie.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  Trie t;
  while (n--) {
    string op, s;
    cin >> op >> s;
    if (op == "insert") t.insert(s);
    else cout << (t.find(s) ? "yes" : "no") << "\n";
  }
}
