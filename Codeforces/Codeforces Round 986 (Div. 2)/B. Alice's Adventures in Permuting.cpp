// ﷽
// Contest: Codeforces Round 986 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2028/problem/B
// Memory Limit: 256
// Time Limit: 1000
// Start: 10 نوف, 2024 06:08:01 م
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
// Function to check if the array is a permutation of [0, 1, ..., n-1]
bool is_permutation(const vi& a, int n) {
    vector<bool> seen(n, false);  // Track elements that are seen
    for (int x : a) {
        if (x >= 0 && x < n) {
            seen[x] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) return false;  // If any element is missing
    }
    return true;
}

// Function to find the MEX (Minimum Excluded Value) of the current array elements
int find_mex(const vi& a, int n) {
    vector<bool> seen(n, false);
    for (int x : a) {
        if (x >= 0 && x < n) {
            seen[x] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) return i;  // The first missing value is the MEX
    }
    return n;  // If no values are missing, the MEX is n
}

void solve() {
    int n, b, c;
    cin >> n >> b >> c;

    vi v(n);
    int operations = 0;
    set<int> out_of_bounds;
    
    // Construct the array and track numbers greater than or equal to n
    for (int i = 0; i < n; ++i) {
        v[i] = b * i + c;
        if (v[i] >= n) {
            out_of_bounds.insert(v[i]);
        }
    }

    // If the array is already a permutation, we don't need any operations
    if (is_permutation(v, n)) {
        cout << 0 << endl;
        return;
    }

    // We need to track missing values in the range [0, n-1]
    int missing_count = 0;
    for (int i = 0; i < n; ++i) {
        if (find(v.begin(), v.end(), i) == v.end()) {
            missing_count++;
        }
    }

    // The number of operations is at least the number of missing elements
    if (missing_count > out_of_bounds.size()) {
        cout << -1 << endl;  // Not enough numbers to replace the missing ones
    } else {
        cout << missing_count << endl;  // Each missing number can be replaced in one operation
    }
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
