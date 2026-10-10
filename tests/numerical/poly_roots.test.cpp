#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/poly_roots.h"

int main() {
  mt19937 gen(71);
  rep(it,0,10000) {
    // product of (x - r_i) for distinct integer roots, times a constant
    int n = gen() % 6 + 1;
    vi rs(21);
    iota(all(rs), -10);
    shuffle(all(rs), gen);
    rs.resize(n);
    sort(all(rs));
    Poly p{{double(gen() % 5 + 1) * (gen() % 2 ? 1 : -1)}};
    for (int r : rs) {
      vec<double> b(sz(p.a) + 1);
      rep(i,0,sz(p.a)) b[i + 1] += p.a[i], b[i] -= r * p.a[i];
      p.a = b;
    }
    vec<double> got = polyRoots(p, -20, 20);
    assert(sz(got) == n);
    rep(i,0,n) assert(abs(got[i] - rs[i]) < 1e-6);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
