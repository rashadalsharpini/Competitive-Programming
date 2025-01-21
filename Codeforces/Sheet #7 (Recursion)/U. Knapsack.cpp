// ﷽
// Contest: Sheet #7 (Recursion)
// Judge: Codeforces
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
// Memory Limit: 256
// Time Limit: 2000
// Start: 16 أغس, 2024 10:45:59 ص
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
const int max_n = 20;
int memo[20][1000];
int weights[max_n], profit[max_n];
int n, w;
int knapsack(int index, int rem){
  if(index == n || rem == 0)
    return 0;
  if(memo[index][rem] != -1)return memo[index][rem];
  if(weights[index] > rem)
    return knapsack(index + 1, rem);
  int include = profit[index] + knapsack(index+1, rem - weights[index]);
  int exclude =  knapsack(index+1, rem);
  return memo[index][rem] = max(include, exclude);

}
void solve() {
  cin>>n>>w;
  memset(memo, -1, sizeof memo);
  for(int i =0;i<n;++i)
    cin>>weights[i]>>profit[i];
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
