// ﷽
// Contest: Educational Codeforces Round 169 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2004/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: 15 أغس, 2024 09:04:14 م
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
void solve(){
  int l, r;cin>>l>>r;
  int L, R;cin>>L>>R;
  int var = max(r, R)+1;
  vi pre(var, 0);
  pre[l - 1]++;pre[r]--;
  pre[L - 1]++;pre[R]--;
  for(int i =1;i<var;++i)
    pre[i] += pre[i - 1];
  debug(pre);
  bool shit = false;
  int look = 0;
  for(int i =0;i<var;++i){
    if(pre[i] == 2){
      shit = true;
      if(pre[i+1]>=1)look++;
      if(pre[i-1]==1)look++;
    }
  }
  if(!shit)cout<<1;
  else cout<<look;
  cout<<endl;
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
