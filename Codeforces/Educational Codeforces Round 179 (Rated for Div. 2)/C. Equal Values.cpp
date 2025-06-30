// ﷽
// Contest: Educational Codeforces Round 179 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2111/problem/C
// Memory Limit: 512
// Time Limit: 2000
// Start: 26 يون, 2025 12:00:14 م
//
#include <bits/stdc++.h>
#include <climits>
using namespace std;
#ifdef Rashad
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
    map<int, int> mp;
    for(int i=0;i<n;++i){
        cin>>v[i];
        mp[v[i]]++;
    }
    if(mp.size()==1){
        cout<<0<<endl;
        return;
    }
    int l=0;
    int mon = LLONG_MAX;
    while(l<n){
        int r = l;
        while(r<n&&v[r]==v[l])
            ++r;
        int lc=1LL*l*v[l];
        int rc=1LL*(n-r)*v[l];
        mon=min(mon, lc+rc);
        l=r;
    }
    cout<<mon<<endl;
}
int32_t main() {
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
