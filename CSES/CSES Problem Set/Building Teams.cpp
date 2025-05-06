// ﷽
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512
// Time Limit: 1000
// Start: Tue 06 May 2025 03:54:54 PM EEST
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
    int nodes, edges;cin>>nodes>>edges;
    vector<vi> adj(nodes+1);
    vector<int> vis(nodes+1, false);
    for (int i = 0; i < edges; i++) {
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi teams(nodes+1);
    function<bool(int)> bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        teams[start] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    teams[v] = 3 - teams[u];
                }else {
                    if(teams[v]==teams[u])
                        return false;
                }

            }
        }
        return true;
    };
    bool f = true;
    for (int i = 1; i <= nodes; i++)
        if(!vis[i]) f &= bfs(i);
    if(!f){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    for (int i = 1; i <= nodes; i++)
        cout<<teams[i]<<" ";
}
int32_t main() {
    /*freopen("whereami.in", "r", stdin);*/
    /*freopen("whereami.out", "w", stdout);*/
    fastio
    int t = 1;
    /*cin>>t;*/
    while (t--)
        solve();
    return 0;
}
