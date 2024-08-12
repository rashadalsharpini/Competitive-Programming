// ﷽
// Contest: Sheet #7 (Recursion)
// Judge: Codeforces
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/T
// Memory Limit: 64
// Time Limit: 2000
// Start: 12 أغس, 2024 03:14:32 م
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
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
/*const int MAX = 31;*/
/*int memo[MAX][MAX];*/
/*int nCr(int n, int r){*/
/*  if (r == 0 || r == n)*/
/*    return 1;*/
/*  if(memo[n][r] != -1)*/
/*    return memo[n][r];*/
/*  memo[n][r] = nCr(n-1, r-1)+nCr(n-1,r);*/
/*  return memo[n][r];*/
/*}*/
int fact(int n){
  if(n<=1)
    return 1;
  return n * fact(n - 1);
}
int nCr(int n, int r){
  return fact(n)/(fact(r)*fact(n-r));
} 
void solve() {
  int n, r;cin>>n>>r;
  /*memset(memo, -1, sizeof(memo));*/
  cout<<nCr(n, r)<<endl;
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
