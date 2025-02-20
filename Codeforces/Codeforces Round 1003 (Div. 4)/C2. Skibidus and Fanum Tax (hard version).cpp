// ﷽
// Contest: Codeforces Round 1003 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2065/problem/C2
// Memory Limit: 256
// Time Limit: 2000
// Start: Sun 09 Feb 2025 05:26:19 PM EET
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

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vi b(m);
  for (int j = 0; j < m; j++){
    cin >> b[j];
  }
  sort(b.begin(), b.end());
  const int INF = 1LL << 60;
  int last = -INF; 
  bool possible = true;

  for (int i = 0; i < n; i++){
    int current = a[i];
    int option1 = (current >= last ? current : INF);
    int need = last + current;
    int option2 = INF;
    auto it = lower_bound(b.begin(), b.end(), need);
    if(it != b.end()){
      option2 = (*it) - current;
    }
    int chosen = min(option1, option2);
    if(chosen == INF){
      possible = false;
      break;
    }
    last = chosen; 
  }
  cout << (possible ? "YES" : "NO") << "\n";
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
