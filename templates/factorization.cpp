//

vector<pair<long long, long long>> factorize(long long p) {
    vector<pair<long long, long long>> ans;
    for (long long i = 2; i * i <= p; i++) {
        long long cnt = 0;
        while (p % i == 0) {
            cnt++;
            p /= i;
        }
        if (cnt > 0) {
            ans.push_back({i, cnt});
        }
    }
    if (p != 1) {
        ans.push_back({p, 1});
    }
    return ans;
}