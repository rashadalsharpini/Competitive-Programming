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

#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
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
int mod = 1000000007;
int fast_power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a % mod;
        a *= a % mod;
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
const int max_n = 1001;
int weights[max_n], values[max_n];
int n, w;
int memo[max_n][max_n];
int knapsack(int index, int rem){
  if(index == n || rem == 0) return 0;
  if(weights[index] > rem) return knapsack(index + 1, rem);
  if(memo[index][rem] != -1) return memo[index][rem];
  int include = values[index] + knapsack(index + 1, rem - weights[index]);
  int exclude = knapsack(index + 1, rem);
  return memo[index][rem] = max(include, exclude);
}
void solve(){
  cin>>n>>w;
  memset(memo, -1, sizeof memo);
  for(int i = 0;i < n; ++i)
    cin>>weights[i]>>values[i];
  cout<<knapsack(0, w)<<endl;
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
