// ﷽
// Contest: Codeforces Round 1014 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/2092/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Tue 20 May 2025 06:48:32 PM EEST
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
    int n;cin>>n;
    vi v(n);
    int sum = 0, odd = 0,
        even = 0, big = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        v[i]%2?odd++:even++;
        big = max(big, v[i]);
    }
    if(even==0||odd==0){
        cout<<big<<endl;
        return;
    }
    for(auto& i:v)sum+=i;
    cout<<sum-odd+1<<endl;
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
