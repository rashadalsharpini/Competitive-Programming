// ﷽
// Contest: 2016 PSUT Coding Marathon
// Judge: Codeforces
// URL: https://codeforces.com/gym/100989/problem/L
// Memory Limit: 256
// Time Limit: 1000
// Start: 24 أغس, 2024 11:33:28 ص
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
vector<int> num;
vector<char> sign;
int n;
int minChanges(int indx, int sum) {
    if (indx == n) {
        if (sum == 0) return 0;
        return INT_MAX;
    }

    int ret = INT_MAX;
    if (indx - 1 >= 0) {
        if (sign[indx - 1] == '+') {
            ret = min(ret, minChanges(indx + 1, sum + num[indx]));
        } else {
            ret = min(ret, minChanges(indx + 1, sum - num[indx]));
        }
    }

    // Case 2: Change the current operator
    if (indx - 1 >= 0) {
        if (sign[indx - 1] == '+') {
            ret = min(retr minChanges(indx + 1, sum - num[indx]) + 1);
        } else {
            ret = min(ret, minChanges(indx + 1, sum + num[indx]) + 1);
        }
    }

    return ret;
}

void solve() {
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num.pb(c - '0');
        } else if (c == '+' || c == '-') {
            sign.pb(c);
        }
    }
    int result = minChanges(1, num[0]);
    cout << (result == INT_MAX ? -1 : result) << endl;
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
