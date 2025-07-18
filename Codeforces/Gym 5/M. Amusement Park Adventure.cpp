// ﷽
// Contest: Gym 5
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/620739/problem/M
// Memory Limit: 1024
// Time Limit: 300
// Start: 11 يول, 2025 10:59:00 م
//
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

#define int long long
#define endl "\n"
// 48 - 57 -> 0 - 9  65 - 90 -> A-Z 97 - 122 -> a-z

void solve() {
    int n, h;cin>>n>>h;
    int x;
    int count = 0;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x<=h)count++;
    }
    cout<<count<<endl;
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
