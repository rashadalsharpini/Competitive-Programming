// ﷽
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1193
// Memory Limit: 512
// Time Limit: 1000
// Start: Mon 05 May 2025 06:11:02 PM EEST
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

//             l  d  r   u  ur  ul  dr dl
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};//i
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};//j
void solve() {
    int n, m;cin>>n>>m;
    vector<vector<char>> mat(n+1, vector<char>(m+1));
    pi start, end;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin>>mat[i][j];
            if(mat[i][j]=='A'){
                start.first=i;
                start.second=j;
            }else if(mat[i][j]=='B'){
                end.first=i;
                end.second=j;
            }
        }
    vector<vector<bool>> vis(n+1, vector<bool>(m+1));
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
