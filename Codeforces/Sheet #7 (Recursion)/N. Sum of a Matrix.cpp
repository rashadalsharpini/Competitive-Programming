// ﷽
// Contest: Sheet #7 (Recursion)
// Judge: Codeforces
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/N
// Memory Limit: 256
// Time Limit: 1000
// Start: 11 أغس, 2024 05:37:43 م
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
void summation(const vector<vi>& v, const vector<vi>& v2, vector<vi>& sum, int i, int j, int r, int c ){
  if(i == r)return;
  if(j == c){
    summation(v, v2, sum, i + 1, 0, r, c);
    return;
  }
  sum[i][j] = v[i][j] + v2[i][j];
  summation(v, v2, sum, i, j + 1, r, c);
}
void solve() {
  int r, c;cin>>r>>c;
  vector<vi> v(r, vi(c));
  vector<vi> v2(r, vi(c));
  vector<vi> sum(r, vi(c));
  for(int i =0;i<r;++i)
    for(int j =0;j<c;++j)
      cin>>v[i][j];
  for(int i =0;i<r;++i)
    for(int j =0;j<c;++j)
      cin>>v2[i][j];
  summation(v, v2, sum, 0, 0, r, c);
  for(int i = 0;i<r;++i){
    for(int j = 0;j < c; ++j)
      cout<<sum[i][j]<<" ";
    cout<<endl;
  }
}
int32_t main() {
    //  freopen("whereami.in", "r", stdin);
    //  freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    /*cin>>t;*/
    while (t--)
        solve();
    return 0;
}
