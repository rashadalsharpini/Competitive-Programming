// ﷽
// Contest: Juniors Phase 1 Practice #5 (Bitmask, Bitset, Bits)
// Judge: Codeforces
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/377898/problem/E
// Memory Limit: 256
// Time Limit: 2000
// Start: 20 مار, 2025 04:46:07 م
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
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
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
  int n;
  cin >> n;
  int comp[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> comp[i][j];
    }
  }
  int bestMask = 0, bestCount = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    int cnt = __builtin_popcount(mask);
    if (cnt <= bestCount) continue;
    vi team;
    int msk = mask, idx = 0;
    while (msk) {
      if (msk & 1) {
        team.push_back(idx);
      }
      idx++;
      msk >>= 1;
    }
    bool valid = true;
    for (int i = 0; i < team.size() && valid; i++) {
      for (int j = i + 1; j < team.size() && valid; j++) {
        int a = team[i], b = team[j];
        if (comp[a][b] == 0 || comp[b][a] == 0) {
          valid = false;
        }
      }
    }
    if (valid) {
      bestCount = cnt;
      bestMask = mask;
    }
  }
  cout << bestCount << "\n";
  int msk = bestMask, j = 0;
  while (msk) {
    if (msk & 1) {
      cout << j + 1 << " ";
    }
    j++;
    msk >>= 1;
  }
  cout << "\n";
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
