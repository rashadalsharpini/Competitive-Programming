// ﷽
// Contest: The 2023 ICPC Egyptian Collegiate Programming Contest (Qualifications Day 8)
// Judge: Codeforces
// URL: https://codeforces.com/group/Rilx5irOux/contest/530044/problem/A
// Memory Limit: 256
// Time Limit: 2000
// Start: 26 يول, 2025 10:17:05 ص
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
    int n,x;cin>>n>>x;
    vector<vi> adj(n+1);
    vi parent(n+1);
    for (int i = 2; i <= n; i++) {
        cin>>parent[i];
        adj[parent[i]].push_back(i);
    }
    vi values(n+1);
    for (int i = 1; i <= n; i++) 
        cin>>values[i];
    vi prefix(n+1, 0);
    auto dfs = [&](auto&& dfs, int p)->void {
        prefix[p]=values[p];
        for (auto v : adj[p]) {
            dfs(dfs, v);
            prefix[p]+=prefix[v];
        }
    };
    dfs(dfs, 1);
    vi nearstAncestor(n+1, -1);

    auto go = [&](auto&&go, int p, int nearst)->void {
        nearstAncestor[p] = nearst;
        for (auto &v : adj[p]) {
            if (prefix[p] >= x)
                go(go, v, p);
            else
                go(go, v, nearst);
        }
    };

    go(go, 1, -1);
    for (int i = 2; i <= n; i++) {
        cout<<nearstAncestor[i]<<' ';
    }
    cout<<endl;

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
