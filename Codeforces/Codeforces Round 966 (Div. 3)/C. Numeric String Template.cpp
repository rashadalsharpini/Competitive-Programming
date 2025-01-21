// ﷽
// Contest: Codeforces Round 966 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2000/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 14 أغس, 2024 04:00:14 م
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
vector<int> primeFactors(int n) {
    vector<int> factors;
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
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z

void solve() {
  int n;cin>>n;
  vi v(n);cin>>v;
  int m;cin>>m;
  string s;
  while(m--){
    cin>>s;
    vector<pair<int, char>> mp;
    vector<pair<char, int>> mpr;
    bool shit = false;
    bool shit1 = false;
    if(s.size() == n){
      for(int i=0;i<n;++i){
        mp.pb({v[i], s[i]});
        mpr.pb({s[i], v[i]});
      }
      sort(all(mp));
      sort(all(mpr));
      for(int i = 0;i<n-1;++i){
        if(mp[i].first == mp[i+1].first && mp[i].second != mp[i+1].second){
          shit = true;
          break;
        }
        if(mpr[i].first == mpr[i+1].first && mpr[i].second != mpr[i+1].second){
          shit1 = true;
          break;
        }

      }
      if(shit || shit1){
        no;
        continue;
      }
    }else{
      no;
      continue;
    }
    yes;
  }
}

int32_t main() {
    //  freopen("whereami.in", "r", stdin);
    //  freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
