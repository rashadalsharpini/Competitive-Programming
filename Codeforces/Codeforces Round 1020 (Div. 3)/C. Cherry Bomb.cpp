// ﷽
// Contest: Codeforces Round 1020 (Div. 3)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2106/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: Thu 24 Apr 2025 05:39:08 PM EET
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
  int n, k;
  cin >> n >> k;
  vi a(n), b(n);
  cin>>a;
  cin>>b;
  int x = -1;
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if (b[i] != -1) {
      int current_x = a[i] + b[i];
      if (x == -1) {
        x = current_x;
      } else if (x != current_x) {
        flag = false;
        break;
      }
    }
  }

  if (!flag) {
    cout << 0 << endl;
    return;
  }






  //every thing is missing
  if (x == -1) {
    int max_a = 0;
    int min_upper = INT_MAX;
    for (int ai : a) {
      max_a = max(max_a, ai);
      min_upper = min(min_upper, ai + k);
    }
    if (max_a > min_upper) {
      cout << 0 << endl;
    } else {
      cout << (min_upper - max_a + 1) << endl;
    }
    return;
  }

  // Check all missing elements
  for (int i = 0; i < n; ++i) {
    if (b[i] == -1) {
      int required_b = x - a[i];
      if (required_b < 0 || required_b > k) {
        flag = false;
        break;
      }
    }
  }

  cout << (flag ? 1 : 0) << endl;
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
