#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/geometry/point_3d.h"
#include "../../lib/geometry/hull_3d.h"

int main() {
  mt19937 gen(11);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,3000) {
    int n = rnd(4, 14);
    vec<P3> A(n);
    for (auto &p : A) p = P3(rnd(-1000, 1000), rnd(-1000, 1000), rnd(-1000, 1000));
    auto vol6 = [&](int i, int j, int k, int l) {
      return (A[j] - A[i]).cross(A[k] - A[i]).dot(A[l] - A[i]);
    };
    bool coplanar = false;
    rep(i,0,n) rep(j,i+1,n) rep(k,j+1,n) rep(l,k+1,n)
      if (vol6(i, j, k, l) == 0) coplanar = true;
    if (coplanar) continue;
    // brute force: a triple is a face iff every other point is on one side
    vec<array<int, 3>> brute;
    rep(i,0,n) rep(j,i+1,n) rep(k,j+1,n) {
      int pos = 0, neg = 0;
      rep(l,0,n) if (l != i && l != j && l != k)
        (vol6(i, j, k, l) > 0 ? pos : neg)++;
      if (!pos || !neg) brute.pb({i, j, k});
    }
    vec<F> fs = hull3d(A);
    vec<array<int, 3>> got;
    for (F f : fs) {
      // faces point outwards
      rep(l,0,n) assert(f.q.dot(A[l] - A[f.a]) <= 0);
      assert((A[f.b] - A[f.a]).cross(A[f.c] - A[f.a]).dot(f.q) > 0);
      array<int, 3> t = {f.a, f.b, f.c};
      sort(all(t));
      got.pb(t);
    }
    sort(all(got));
    assert(got == brute);
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
