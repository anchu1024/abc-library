// Library: https://github.com/anchu1024/abc-library

#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;

const int INF = 1e9;
// const ll INF = 1e18;

const ll MOD = 998244353;
// const ll MOD = 1000000007;

// modをとる
template <typename T>
void take_mod(T& a, T m) {
    a += m;
    a %= m;
}

// 考察

/**/

// 確認

// cinを忘れない
// 変数名の重複に注意
// modは取りましたか？
// 変数の宣言場所
// 0-indexedか1-indexedか
// 境界の等号
// 配列の宣言(push_back前提じゃないか)
// 無向か有向か
// 型を間違えない
// グリッドで縦と横を逆にしない

long long modpow(long long a, long long b, long long m) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long x = modpow(a, b / 2, m);
        return x * x % m;
    }
    long long x = modpow(a, b - 1, m);
    return x * a % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}