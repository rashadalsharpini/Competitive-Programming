// ﷽
// Contest: Juniors Phase 1 Practice #5 (Bitmask, Bitset, Bits)
// Judge: Codeforces
// URL: https://codeforces.com/group/3nQaj5GMG5/contest/377898/problem/H
// Memory Limit: 256
// Time Limit: 2000
// Start: 20 مار, 2025 08:48:51 م
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
  vi a(n);
  cin>>a;

  int max_or = 0;
  for (int num : a)
    max_or |= num;
  if (max_or == 0) {
    cout << 1 << endl;
    return;
  }

  int min_length = n;
  vector<pair<int, int>> prev_or;

  for (int i = 0; i < n; ++i) {
    vector<pair<int, int>> temp;
    for (auto &p : prev_or) {
      temp.emplace_back(p.first | a[i], p.second);
    }
    temp.emplace_back(a[i], i);

    unordered_map<int, int> current_map;
    for (auto &p : temp) {
      int or_val = p.first;
      int start = p.second;
      if (current_map.find(or_val) == current_map.end() || current_map[or_val] < start) {
        current_map[or_val] = start;
      }
    }

    prev_or.clear();
    for (auto &entry : current_map) {
      prev_or.emplace_back(entry.first, entry.second);
    }

    if (current_map.count(max_or)) {
      int current_start = current_map[max_or];
      min_length = min(min_length, i - current_start + 1);
    }
  }

  cout << min_length << endl;
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
