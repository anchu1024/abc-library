// aのb乗のmod mをオーバーフローせずに求めるための累乗関数
// modpow(a, b, m) : aのb乗のmod m
// O(log b)

long long modpow(long long a, long long b, long long m) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long x = modpow(a, b / 2, m);
        return x * x % m;
    }
    long long x = modpow(a, b - 1, m);
    return x * a % m;
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