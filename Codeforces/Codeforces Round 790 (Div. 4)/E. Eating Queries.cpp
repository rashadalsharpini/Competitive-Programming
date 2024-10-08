// ﷽
// Contest: Codeforces Round 790 (Div. 4)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/1676/E
// Memory Limit: 256
// Time Limit: 3500
// Start: 01 أغس, 2024 09:30:59 م
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

typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vll vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define pll pair<long long, long long>
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

void solve() {
  int n, q;cin>>n>>q;
  vll v(n);cin>>v;
  sort(v.rbegin(), v.rend());
  vll ps(n);
  ps[0] = v[0];
  for(int i = 1;i<n;++i)
    ps[i] = ps[i - 1] + v[i];
  int x;
  while(q--){
    cin>>x;
    auto it = lower_bound(ps.begin(), ps.end(), x) - ps.begin();
    if(it<n)
      cout << it+1 << endl;
    else
      cout << -1 << endl;
    }
}
int32_t main() {
    //  freopen("whereami.in", "r", stdin);
    //  freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
