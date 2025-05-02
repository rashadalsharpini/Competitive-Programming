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
  for (T &x : data) input >> x;
  return input;
}
template <typename T> ostream &operator<<(ostream &output, const vector<T> &data) {
  for (const T &x : data) output << x << ' ';
  return output;
}
const int MOD = 1e9+7;

void solve() {
    int nodes, edges;cin>>nodes>>edges;
    vector<vi> adj(nodes+1);
    vector<int> vis(nodes+1, false);
    for (int i = 0; i < edges; i++) {
        int u, v;cin>>u>>v;
        adj[u].push_back(v);
    }
    vi topo;
    bool notCyclic=1;
    function<void(int)> dfs = [&](int p) {
        vis[p] = 2;
        for (auto v : adj[p]) {
            if (!vis[v]) dfs(v);
            else if(vis[v]==2)notCyclic=0;
        }
        vis[p]=1;
        topo.push_back(p);
    };
    for (int i = 1; i <= nodes; i++) {
        if(!vis[i])dfs(i);
    }
    if(notCyclic)cout<<topo<<endl;
    else cout<<-1<<endl;
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
