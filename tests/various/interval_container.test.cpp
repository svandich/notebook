#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/various/interval_container.h"

int main() {
  mt19937 gen(101);
  rep(it,0,2000) {
    set<pii> is;
    vec<bool> in(40);
    rep(op,0,50) {
      int L = gen() % 40, R = gen() % 40;
      if (L > R) swap(L, R);
      bool add = gen() % 2;
      if (add) addInterval(is, L, R);
      else removeInterval(is, L, R);
      rep(i,L,R) in[i] = add;
      // the set holds exactly the maximal runs of covered points
      vec<pii> want;
      rep(i,0,40) if (in[i]) {
        if (i && in[i - 1]) want.back()[1] = i + 1;
        else want.pb({i, i + 1});
      }
      assert(vec<pii>(all(is)) == want);
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
