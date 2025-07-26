// ﷽
// Contest: The 2023 ICPC Egyptian Collegiate Programming Contest (Qualifications Day 8)
// Judge: Codeforces
// URL: https://codeforces.com/group/Rilx5irOux/contest/530044/problem/E
// Memory Limit: 256
// Time Limit: 1000
// Start: 25 يول, 2025 06:30:17 م
//
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#ifdef Rashad
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);


// #define int long long
// #define double long double
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a).size()
#define pb push_back
// #define mp make_pair
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
    vi o(n),m(n);cin>>o>>m; int oowatched=0;
    int oliked=0;
    int omwatched=0;
    int mliked=0;
    for (int i = 0; i < n; i++) {
        if(o[i]){
            oowatched++;
            if(m[i]==0)oliked++;
        }
        if(m[i]){
            omwatched++;
            if(o[i]==0)mliked++;
        }
    }
    double op=oowatched?(double)oliked/oowatched*100.0:0.0;
    double mp=omwatched?(double)mliked/omwatched*100.0:0.0;
    cout<<fixed<<setprecision(6)<<op<<" "<<mp<<endl;

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
