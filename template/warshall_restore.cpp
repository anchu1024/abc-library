
#include <bits/stdc++.h>
using namespace std;

// via[i][j] stores the intermediate vertex k.
// Initialize via[i][j] = i.

void restorePath_Warshall_dfs(const auto& via, vector<ll>& path, ll u, ll v) {
    ll mid = via[u][v];

    if (mid == u) {
        if (u != v) path.push_back(u);
        return;
    }

    restorePath_Warshall_dfs(via, path, u, mid);
    restorePath_Warshall_dfs(via, path, mid, v);
}

void restorePath_Warshall(const auto& via, vector<ll>& path, ll start,
                          ll goal) {
    path.clear();

    if (start == goal) {
        path.push_back(start);
        return;
    }

    restorePath_Warshall_dfs(via, path, start, goal);
    path.push_back(goal);
}
