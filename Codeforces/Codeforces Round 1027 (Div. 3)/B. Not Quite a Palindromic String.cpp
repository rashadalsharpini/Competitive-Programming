// ﷽
// Contest: Codeforces Round 1027 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2114/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: Fri 30 May 2025 05:56:32 PM EEST
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
    int n, k;cin>>n>>k;
    string s;cin>>s;
    int one=0, zero=0;
    for (int i = 0; i < n; i++)
        s[i]=='1'?one++:zero++;
    int minK =llabs(zero-(n/2));
    int maxK = llabs((zero/2)+(one/2));
    if(minK<=k&&maxK>=k&& (k - minK)%2==0)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
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

