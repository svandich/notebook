#include "../template.h"
/* -
name = "Randint + rng"
source = "i made it the fuck up"
[info]
description = "Generates random integers from l to r, rng also allows to use shuffle"
time = ""
- */

#include <random>
#include <chrono>
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll rnd(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r)(rng);
}
// shuffle(v.begin(), v.end(), rng);

