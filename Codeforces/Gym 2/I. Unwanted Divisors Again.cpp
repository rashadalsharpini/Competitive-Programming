// ﷽
// Contest: Gym 2
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/618821/problem/I
// Memory Limit: 512
// Time Limit: 5000
// Start: 30 يون, 2025 03:41:37 م
//
#include <bits/stdc++.h>
using namespace std;
#ifdef Rashad
// #include "debug.hpp"
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
vector<int> divisors(int m) {
    vector<int> d;
    for (int i = 2; i * i <= m; i++) {
        if (m % i == 0) {
            d.push_back(i);
            if (i * i != m) d.push_back(m / i);
        }
    }
    return d;
}
vector<int> getDivisors(int n) {
  vector<int> divisors;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i * i != n) {
        divisors.push_back(n / i);
      }
    }
  }
  return divisors;
}
void solve() {
    int n,m;cin>>n>>m;
    vector<int>a(n);cin>>a;
    auto divs=divisors(m);
    // cout<<divs<<endl;
    sort(all(a));
    divs.push_back(m);
    int mx=a[n-1];
    int ans=0;
    for(auto it:divs){
        bool f=false;
        for(int j=it;j<=mx;j+=it){
            f|=binary_search(all(a),j);
            if(f)break;
        }
        ans+=!f;
    }
    cout<<ans<<endl;
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
