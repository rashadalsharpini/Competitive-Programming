// ﷽
// Contest: Codeforces Round 986 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2028/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 10 نوف, 2024 06:49:16 م
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
    int n, m, v; 
    cin >> n >> m >> v;  // number of sections, creatures, and minimum tastiness
    
    vi cake(n);
    int total_sum = 0;
    
    // Read the tastiness values and calculate the total sum
    for (int i = 0; i < n; ++i) {
        cin >> cake[i];
        total_sum += cake[i];
    }
    
    // If total tastiness is less than m * v, it's impossible to make the creatures happy
    if (total_sum < m * v) {
        cout << -1 << endl;
        return;
    }

    // We'll try to find the m pieces with the smallest sum of at least v each
    int required_sum = m * v;  // The sum of tastiness we need for the m creatures
    
    vector<int> prefix_sum(n + 1, 0);  // To compute subarray sums efficiently
    
    // Compute prefix sum
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + cake[i];
    }
    
    // To keep track of the end points of valid subarrays that sum >= v
    vector<int> subarrays;
    
    // Try to find m subarrays with sum >= v using a sliding window or greedy approach
    int pieces = 0;
    int current_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        current_sum += cake[i];
        if (current_sum >= v) {
            pieces++;
            current_sum = 0;  // Start a new piece after the current partition
        }
    }

    if (pieces < m) {
        cout << -1 << endl;  // If it's not possible to divide the cake into m pieces, print -1
    } else {
        // The remaining sum for Alice is total_sum - required_sum
        cout << total_sum - required_sum << endl;  
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
