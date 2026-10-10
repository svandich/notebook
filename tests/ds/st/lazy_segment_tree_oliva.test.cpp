#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../../lib/template.h"
#include "../../../lib/ds/st/lazy_segment_tree_oliva.h"
const ll mod = 998244353;
#include "../../../lib/ds/st/tag.h"

ll mod_plus(ll a, ll b) { return (a + b) % mod; }

void push_tag(Tag &parent, Tag &child, int, int, int, int) {
  child = child(parent);
}

void apply_tag(Tag &tag, ll &ans, int l, int r) {
  ans = tag.map(ans, l, r + 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vec<ll> A(n);
  for (auto &a : A) {
    cin >> a;
  }
  segment_tree_lazy<ll, Tag, mod_plus, push_tag, apply_tag> tree(A);
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 0) {
      int b, c;
      cin >> b >> c;
      tree.update(l, r - 1, {b, c});
    } else if (t == 1) {
      cout << tree.query(l, r - 1) << "\n";
    }
  }
}
