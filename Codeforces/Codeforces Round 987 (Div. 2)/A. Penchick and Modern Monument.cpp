// ﷽
// Contest: Codeforces Round 987 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2031/problem/0
// Memory Limit: 256
// Time Limit: 1000
// Start: 15 نوف, 2024 02:36:14 م
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
#define allr(a) (a).rbegin(), (a).rend()
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
const int MOD = 1e9+7;
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
bool canSort(const vector<int>& p, int n) {
    vector<int> positions(n);
    for (int i = 0; i < n; ++i) {
        positions[p[i] - 1] = i;  // Map values to their indices
    }
    for (int i = 0; i < n - 1; ++i) {
        if (positions[i + 1] < positions[i]) {  // Blocks are not contiguous
            return false;
        }
    }
    return true;
}
void solve() {
  int n;cin>>n;
  vi v(n);cin>>v;
  set<int> ss(all(v));
  if(ss.size()==1&&n>1){
    cout<<1<<endl;
    return;
  }
  vi vs=v;
  sort(all(vs));
  debug(v);
  debug(vs);
  int op=0;
  for (int i = 0; i < n; i++) {
    if(v[i]!=vs[i]){
      op++;
    }
  }
  cout<<(vs[n-1]==n?op:op-1)<<endl;
  
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