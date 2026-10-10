#define PROBLEM "https://judge.yosupo.jp/problem/deque"
#include "../../lib/template.h"
#include "../../lib/ds/treap_node.h"
#include "../../lib/ds/treap.h"

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int q;
  cin >> q;
  Treap<Node> t;
  while (q--) {
    int type;
    cin >> type;
    if (type == 0) {
      ll x;
      cin >> x;
      t.insert(t.make_node(x), 0);
    } else if (type == 1) {
      ll x;
      cin >> x;
      t.insert(t.make_node(x), t.cnt(t.root));
    } else if (type == 2) {
      t.root = t.split(t.root, 1).second;
    } else if (type == 3) {
      t.root = t.split(t.root, t.cnt(t.root) - 1).first;
    } else {
      int i;
      cin >> i;
      Node* v = t.root;
      while (t.cnt(v->l) != i) {
        if (i < t.cnt(v->l)) v = v->l;
        else i -= t.cnt(v->l) + 1, v = v->r;
      }
      cout << v->x << "\n";
    }
  }
}
