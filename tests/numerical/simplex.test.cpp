#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "../../lib/template.h"
#include "../../lib/numerical/simplex.h"

// 2 variable LPs, compared with checking every vertex of the feasible region
int main() {
  mt19937 gen(83);
  auto rnd = [&](int l, int r) { return int(gen() % (r - l + 1)) + l; };
  rep(it,0,20000) {
    int m = rnd(1, 5);
    vvd A(m, vd(2));
    vd b(m), c = {double(rnd(-5, 5)), double(rnd(-5, 5))};
    rep(i,0,m) A[i] = {double(rnd(-5, 5)), double(rnd(-5, 5))}, b[i] = rnd(-5, 10);
    // x <= 10 and y <= 10 keep the region bounded
    A.pb({1, 0}), b.pb(10), A.pb({0, 1}), b.pb(10);
    vvd lines = A;
    vd rhs = b;
    lines.pb({-1, 0}), rhs.pb(0), lines.pb({0, -1}), rhs.pb(0);
    double best = -inf;
    rep(i,0,sz(lines)) rep(j,i+1,sz(lines)) {
      double det = lines[i][0] * lines[j][1] - lines[i][1] * lines[j][0];
      if (abs(det) < eps) continue;
      double x = (rhs[i] * lines[j][1] - lines[i][1] * rhs[j]) / det;
      double y = (lines[i][0] * rhs[j] - rhs[i] * lines[j][0]) / det;
      bool ok = true;
      rep(k,0,sz(lines)) if (lines[k][0] * x + lines[k][1] * y > rhs[k] + 1e-7) ok = false;
      if (ok) best = max(best, c[0] * x + c[1] * y);
    }
    vd x;
    double got = LPSolver(A, b, c).solve(x);
    if (best == -inf) {
      assert(got == -inf);
      continue;
    }
    assert(abs(got - best) < 1e-6);
    rep(k,0,sz(A)) assert(A[k][0] * x[0] + A[k][1] * x[1] <= b[k] + 1e-6);
    assert(x[0] >= -1e-6 && x[1] >= -1e-6);
  }
  // unbounded: maximize x with only y bounded
  vd x;
  assert(LPSolver({{0, 1}}, {1}, {1, 0}).solve(x) == inf);
  ll a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}
