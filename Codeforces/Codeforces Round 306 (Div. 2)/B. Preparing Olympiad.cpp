// ﷽
// Contest: Codeforces Round 306 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/550/B
// Memory Limit: 256
// Time Limit: 2000
// Start: 02 أغس, 2024 03:31:54 م
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
  int n, l, r, x;cin>>n>>l>>r>>x;
  vi v(n);cin>>v;
  vi vv;
  int count = 0;
  for(int i = 0;i<(1<<n); ++i){
    int msk = i;
    int j = 0;
    int sum = 0;
    while(msk){
      if(msk&1){
        vv.pb(v[j]);
        sum += v[j];
      }
      j++;
      msk>>=1;
    }
    sort(all(vv));
    if(sum >= l && sum <= r && sz(vv) >= 2 && (vv[sz(vv) - 1] - vv[0] >= x))
      count++;
    vv.clear();
  }
  cout<<count<<endl;
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
