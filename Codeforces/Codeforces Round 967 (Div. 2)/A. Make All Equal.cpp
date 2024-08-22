// ﷽
// Contest: Codeforces Round 967 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2001/problem/A
// Memory Limit: 256
// Time Limit: 1000
// Start: 20 أغس, 2024 05:38:25 م
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
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
vector<pair<int, int>> countElements(const vector<int>& vec) {
    vector<pair<int, int>> result;

    // Sort the input vector to group identical elements
    vector<int> sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end());

    for (size_t i = 0; i < sortedVec.size();) {
        int element = sortedVec[i];
        int count = 0;

        // Count occurrences of the current element
        while (i < sortedVec.size() && sortedVec[i] == element) {
            count++;
            i++;
        }

        // Add the pair (element, count) to the result vector
        result.push_back({element, count});
    }

    return result;
}
void solve() {
  int n;cin>>n;
  vi v(n);cin>>v;
  set<int> s;
  for(int i = 0;i<n;++i)
    s.insert(v[i]);
  /*debug(s);*/
  if(n == 1){cout<<0<<endl;return;}
  if(n == s.size()){cout<<n-1<<endl;return;}
  if(n == s.size() + 1){cout<<n-2<<endl;return;}
  vector<pair<int, int>> vp = countElements(v);
  debug(v);
  debug(vp);
  int big =0,sum=0;
  for(int i = 0;i<vp.size();++i){
    big = max(vp[i].second,big);
    sum+=vp[i].second;
  }
  cout<<sum - big<<endl;

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
