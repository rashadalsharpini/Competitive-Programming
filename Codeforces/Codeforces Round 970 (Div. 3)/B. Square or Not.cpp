// ﷽
// Contest: Codeforces Round 970 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2008/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: 03 سبت, 2024 10:35:41 م
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
#define yes cout << "Yes\n"
#define no cout << "No\n"
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
  int n;cin>>n;
  string s;cin>>s;
  int dump = sqrt(n);
  if(dump*dump != n){
    no;
    return;
  }
  char arr[dump][dump];
  for(int i =0;i<dump;++i)
    for(int j=0;j<dump;++j)
      arr[i][j] = s[i * dump +j];

  bool isValid = true;
  // top and bottom
  for (int i = 0; i < dump; ++i) {
    if (arr[0][i] != '1' || arr[dump - 1][i] != '1') {
      isValid = false;
      break;
    }
  } 
  // left and right
  for (int i = 1; i < dump - 1; ++i) {
    for (int j = 1; j < dump - 1; ++j) {
      if (arr[i][j] != '0') {
        isValid = false;
        break;
      }
    }
    if (!isValid) break;
  }
  // inner
  for (int i = 1; i < dump - 1; ++i) {
    for (int j = 1; j < dump - 1; ++j) {
      if (arr[i][j] != '0') {
        isValid = false;
        break;
      }
    }
    if (!isValid) break;
  }  
  if(isValid)
    yes;
  else 
    no;

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
