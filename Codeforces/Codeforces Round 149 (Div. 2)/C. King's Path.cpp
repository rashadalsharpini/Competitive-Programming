// ﷽
// Contest: Codeforces Round 149 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/242/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 27 يول, 2025 09:53:29 م
//
#include <bits/stdc++.h>
using namespace std;
#ifdef Rashad
#include "debug.hpp"
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

void solve() {
    pair<int, int> start, end;
    cin>>start.first>>start.second>>end.first>>end.second;
    int n;cin>>n;
    set<pair<int, int>> allowed;
    for (int i = 0; i < n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) {
            allowed.insert({r, j});
        }
    }
    queue<pair<int, int>> q;
    map<pair<int, int>, int> dist;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x, y) == end) {
            cout<<dist[{x, y}]<<endl;
            return;
        }
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            pair<int, int> np = {nx, ny};
            if (allowed.count(np) && dist.find(np) == dist.end()) {
                dist[np] = dist[{x, y}] + 1;
                q.push(np);
            }
        }
    }

    cout<<-1<<endl;
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
