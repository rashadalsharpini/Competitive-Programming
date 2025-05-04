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
#define vi vector<int>
#define pi pair<int,int>
#define OO 2e9
#define endl "\n"
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template <typename T> istream &operator>>(istream &input, vector<T> &data) {
    for (T &x : data) input >> x;
    return input;
}
template <typename T> ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x : data) output << x << ' ';
    return output;
}
const int MOD = 1e9+7;

//shortest dist between s and t:
//1.start bfs from s bfs(s)
//2.dist = levels[t]
void solve() {
    int nodes, edges;cin>>nodes>>edges;
    vector<vi> adj(nodes+1);
    vector<bool> vis(nodes+1, false);
    for (int i = 0; i < edges; i++) {
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi levels(nodes+1, -1);
    vi parent(nodes+1, -1);
    function<void(int)> bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        levels[start] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    levels[v] = levels[u] + 1;
                    parent[v] = u;
                }
            }
        }
    };
    bfs(1);
    int cur = nodes;
    stack<int> st;
    while(cur!=-1)
    {
        st.push(cur);
        cur = parent[cur];
    }
    cout<<levels[nodes]<<endl;
    while (!st.empty()) {
        cur = st.top();
        st.pop();
        cout<<cur<<" ";
    }
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
