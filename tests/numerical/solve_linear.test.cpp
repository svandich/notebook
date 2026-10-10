#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/solve_linear.h"

int main() {
  mt19937 gen(73);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,20000) {
    int n = rnd(1, 6), m = rnd(1, 6), rank = rnd(0, min(n, m));
    // A = B * C with B n x rank and C rank x m has rank `rank` (w.h.p.)
    vec<vd> B(n, vd(rank)), C(rank, vd(m)), A(n, vd(m));
    for (auto &r : B) for (auto &v : r) v = rnd(-5, 5);
    for (auto &r : C) for (auto &v : r) v = rnd(-5, 5);
    rep(i,0,n) rep(j,0,m) rep(k,0,rank) A[i][j] += B[i][k] * C[k][j];
    vd x0(m), b(n);
    for (auto &v : x0) v = rnd(-5, 5);
    rep(i,0,n) rep(j,0,m) b[i] += A[i][j] * x0[j];
    // perturbing b may make the system inconsistent (when rank < n)
    bool consistent = rnd(0, 1);
    if (!consistent) b[rnd(0, n - 1)] += rnd(1, 5);
    auto A2 = A;
    auto b2 = b;
    vd x(m);
    int r = solveLinear(A2, b2, x);
    if (r == -1) {
      assert(!consistent);
      continue;
    }
    rep(i,0,n) {
      double s = 0;
      rep(j,0,m) s += A[i][j] * x[j];
      assert(abs(s - b[i]) < 1e-6);
    }
    if (consistent) {
      auto A3 = A;
      vd b3(n), x3(m);
      int r0 = solveLinear(A3, b3, x3);
      assert(r == r0 && r <= rank);
    }
  }
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
