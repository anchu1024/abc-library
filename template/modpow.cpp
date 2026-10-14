// aのb乗のmod mをオーバーフローせずに求めるための累乗関数
// modpow(a, b, m) : aのb乗のmod m
// 計算量 O(log b)

long long modpow(long long a, long long b, long long m) {
    a %= m;
    long long r = 1 % m;
    while (b > 0) {
        if (b & 1) r = (__int128)r * a % m;
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return r;
}

int modpow(int a, int b, int m) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long x = modpow(a, b / 2, m);
        return x * x % m;
    }
    long long x = modpow(a, b - 1, m);
    return x * a % m;
}

long long inverse(long long a, long long m) {
    long long b = m - 2;
    a %= m;
    long long r = 1 % m;
    while (b > 0) {
        if (b & 1) r = (__int128)r * a % m;
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return r;
}