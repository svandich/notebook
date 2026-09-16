#include "../template.h"
/* -
   name = "Random Number Generator"
   [info]
   description = "Random number generation for integer ranges from l to r with clock based seeds."
   time = "$O(log(r-l))$ $->$ amortized $O(1)$"
   - */
#include <random>
#include <chrono>

mt19937_64 rng(
		chrono::steady_clock::now().time_since_epoch().count());

long long rnd(long long l, long long r) {
	return uniform_int_distribution<long long>(l, r)(rng);
}

// Can be used in: shuffle(v.begin(), v.end(), rng);
