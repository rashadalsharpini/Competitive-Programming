// ﷽
// Contest: Standard #1 (Frequency , prefix sum , vector , pair ,struct)
// Judge: Codeforces
// URL: https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/I
// Memory Limit: 256
// Time Limit: 1000
// Start: 28 أغس, 2024 04:04:07 م
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
#define fastio                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
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
int MOD = 1e9+7;
int fast_power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a % MOD;
        a *= a % MOD;
        b >>= 1;
    }
    return res;
}
vi primeFactors(int n) {
    vi factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}
// 48 - 57 -> 0 - 9  65 - 90 -> A-Z 97 - 122 -> a-z

void solve() {
  int n, q;cin>>n>>q;
  vi v(n);cin>>v;
  while(q--){
    string s;cin>>s;
    if(s == "pop_back"){
      v.pop_back();
    }else if(s == "front"){
      cout<<v[0]<<endl;
    }else if(s == "back"){
      cout<<v.back()<<endl;
    }else if(s == "sort"){
      int l, r;cin>>l>>r;
      sort(v.begin() + (l - 1), v.begin() + r);
    }else if(s == "reverse"){
      int l, r;cin>>l>>r;
      reverse(v.begin() + (l - 1), v.begin() + r);
    }else if(s == "print"){
      int pos;cin>>pos;
      cout<<v[pos - 1]<<endl;
    }else if(s == "push_back"){
      int x;cin>>x;
      v.push_back(x);
    }
  }
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
