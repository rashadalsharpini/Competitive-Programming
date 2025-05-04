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
    int n, m;cin>>n>>m;
    map<int, int> vis, parent;
    function<int(int)> bfs = [&](int start) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        vis[start] = true;
        while (!q.empty()) {
            int u = q.front().first; 
            int u_level = q.front().second;
            q.pop();
            if(u==m){
                return u_level;
            }
            if(u > 1 &&!vis[u - 1]) {
                q.push({u-1, u_level+1});
                vis[u-1]=true;
            }
            if(!vis[u*2] && u < m) {
                q.push({u*2, u_level+1});
                vis[u*2]=true;
            }

        }
    };
    cout<<bfs(n);
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
