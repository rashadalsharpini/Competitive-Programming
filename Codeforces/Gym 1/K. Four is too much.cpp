// ﷽
// Contest: Gym 1
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/618800/problem/K
// Memory Limit: 256
// Time Limit: 1000
// Start: 29 يون, 2025 02:59:06 م
//
#include <bits/stdc++.h>
using namespace std;
#ifdef Rashad
// #include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define pi pair<int,int>
#define OO 2e9
#define endl "\n"
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template <typename T> istream &operator>>(istream &input, vector<T> &data) {
    for (T &x : data)
    input >> x;
    return input;
}
template <typename T> ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x : data)
    output << x << " ";
    return output;
}
const int MOD = 1e9+7;
// 48 - 57 -> 0 - 9  65 - 90 -> A-Z 97 - 122 -> a-z


const int INF = 1e18;
vector<pair<int, int>> vp;
vector<vector<int>> dp;

int rec(int i, int rem) {
    if (rem == 0) return 0;
    if (i == vp.size()) return INF;
    if (dp[i][rem] != -1) return dp[i][rem];

    int res = rec(i + 1, rem);
    if (rem >= vp[i].first) {
        int take = rec(i + 1, rem - vp[i].first);
        if (take != INF) res = min(res, take + vp[i].second);
    }

    return dp[i][rem] = res;
}

void solve() {
    int X, N;
    cin >> X >> N;
    vp.clear();
    vp.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> vp[i].first >> vp[i].second;
    }

    dp.assign(N + 1, vector<int>(X + 1, -1));
    int ans = rec(0, X);
    cout << (ans == INF ? -1 : ans) << endl;
}
int32_t main() {
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
