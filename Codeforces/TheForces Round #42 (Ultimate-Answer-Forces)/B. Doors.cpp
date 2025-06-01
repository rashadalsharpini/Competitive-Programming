// ﷽
// Contest: TheForces Round #42 (Ultimate-Answer-Forces)
// Judge: Codeforces
// URL: https://codeforces.com/gym/105846/problem/B
// Memory Limit: 256
// Time Limit: 1000
// Start: Fri 23 May 2025 10:38:43 PM EEST
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
const int NEG_INF = -(1ll<<60);
int n, x;
int c[105], a[105];
int memo[105][105];
bool vis[105][105];
 
int dp(int i, int k) {
    if (i == 0)
        return (k == 0 ? x : NEG_INF);
    int &ans = memo[i][k];
    if (vis[i][k]) return ans;
    vis[i][k] = true;
    ans = NEG_INF;
 
    // pay
    int prev = dp(i-1, k);
    if (prev >= c[i])
        ans = max(ans, prev - c[i] + a[i]);
    // zero
    if (k > 0) {
        int prev2 = dp(i-1, k-1);
        if (prev2 >= 0)
            ans = max(ans, prev2 + a[i]);
    }
    return ans;
}
 
void solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    memset(vis, false, sizeof vis);
    for(int k = 0; k <= n; k++)
        if (dp(n, k) >= 0) {
            cout << k << endl;
            return;
        }
}
int32_t main() {
    /*freopen("whereami.in", "r", stdin);*/
    /*freopen("whereami.out", "w", stdout);*/
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
