#include <bits/stdc++.h>
using namespace std;

// 素因数分解します。返値は素数とそれの指数のペアの配列です。
// 素数は小さい方から格納されます。
// 計算量
//  初期化 : O(N log log N)
//  素因数分解 : O(log N)

struct Factorize {
    int limit;
    vector<int> smallest;

    explicit Factorize(int limit) : limit(limit), smallest(limit + 1) {
        iota(smallest.begin(), smallest.end(), 0);

        for (int p = 2; 1LL * p * p <= limit; ++p) {
            if (smallest[p] != p) continue;

            for (int v = p * p; v <= limit; v += p) {
                if (smallest[v] == v) {
                    smallest[v] = p;
                }
            }
        }
    }

    vector<pair<long long, long long>> factorize(long long x) const {
        vector<pair<long long, long long>> factors;

        while (x > 1) {
            int prime = smallest[x];
            long long exponent = 0;

            while (x % prime == 0) {
                x /= prime;
                ++exponent;
            }

            factors.emplace_back(prime, exponent);
        }

        return factors;
    }
};
