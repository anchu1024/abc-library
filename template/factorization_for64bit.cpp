
#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;
using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Modular arithmetic
u64 mul_mod(u64 a, u64 b, u64 mod) { return (u128)a * b % mod; }

u64 pow_mod(u64 a, u64 e, u64 mod) {
    u64 result = 1;

    while (e > 0) {
        if (e & 1) result = mul_mod(result, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }

    return result;
}

// Deterministic Miller-Rabin for 64-bit integers
bool is_prime(ll value) {
    if (value < 2) return false;

    u64 n = value;

    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL,
                  29ULL, 31ULL, 37ULL}) {
        if (n % p == 0) return n == p;
    }

    u64 d = n - 1;
    int s = 0;

    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }

    for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL,
                  1795265022ULL}) {
        if (a % n == 0) continue;

        u64 x = pow_mod(a % n, d, n);

        if (x == 1 || x == n - 1) continue;

        bool passed = false;

        for (int r = 1; r < s; ++r) {
            x = mul_mod(x, x, n);

            if (x == n - 1) {
                passed = true;
                break;
            }
        }

        if (!passed) return false;
    }

    return true;
}

// Brent's variant of Pollard's Rho
u64 pollard_rho(u64 n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;

    auto f = [&](u64 x, u64 c) { return (u128(mul_mod(x, x, n)) + c) % n; };

    while (true) {
        u64 y = rng() % (n - 1) + 1;
        u64 c = rng() % (n - 1) + 1;
        u64 g = 1, r = 1, q = 1;
        u64 x = 0, ys = 0;
        const u64 batch = 128;

        while (g == 1) {
            x = y;

            for (u64 i = 0; i < r; ++i) {
                y = f(y, c);
            }

            u64 k = 0;

            while (k < r && g == 1) {
                ys = y;
                u64 count = min(batch, r - k);

                for (u64 i = 0; i < count; ++i) {
                    y = f(y, c);
                    u64 diff = x > y ? x - y : y - x;
                    q = mul_mod(q, diff, n);
                }

                g = gcd(q, n);
                k += count;
            }

            r *= 2;
        }

        if (g == n) {
            do {
                ys = f(ys, c);
                u64 diff = x > ys ? x - ys : ys - x;
                g = gcd(diff, n);
            } while (g == 1);
        }

        if (g != n) return g;
    }
}

// Collect prime factors recursively
void factorize_rec(u64 n, vector<ll>& factors) {
    if (n == 1) return;

    if (is_prime((ll)n)) {
        factors.push_back((ll)n);
        return;
    }

    u64 d = pollard_rho(n);

    factorize_rec(d, factors);
    factorize_rec(n / d, factors);
}

// Return prime factors with multiplicity, in ascending order
vector<ll> pollard_prime_factorize(ll n) {
    if (n < 1) {
        throw invalid_argument("n must be positive");
    }

    vector<ll> factors;
    factorize_rec((u64)n, factors);
    sort(factors.begin(), factors.end());

    return factors;
}

// Return (prime, exponent) pairs
vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<ll> factors = pollard_prime_factorize(n);
    vector<pair<ll, ll>> result;

    for (ll p : factors) {
        if (result.empty() || result.back().first != p) {
            result.emplace_back(p, 1);
        } else {
            ++result.back().second;
        }
    }

    return result;
}