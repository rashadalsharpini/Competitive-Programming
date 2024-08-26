// ﷽
// Contest: Codeforces Round 968 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2003/problem/C
// Memory Limit: 256
// Time Limit: 2000
// Start: 25 أغس, 2024 06:06:00 م
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
int countGoodPairs(const string &s) {
    int n = s.length();
    unordered_map<char, int> freq;  // To store the frequency of each character
    int goodPairs = 0;

    // Count frequency of each character in the string
    for (char c : s) {
        freq[c]++;
    }

    // Calculate the number of good pairs for each character
    for (auto &entry : freq) {
        int count = entry.second;
        // The number of good pairs for a character is C(count, 2) = count * (count - 1) / 2
        goodPairs += (count * (count - 1)) / 2;
    }

    return goodPairs;
}
void solve() {
  int n;cin>>n;
  string s;cin>>s;
  int big = 0;
  int big2 = 0;
  string s2;
  do{
    big = max(big, countGoodPairs(s));
    if(big2 == big)
      s2 = s;
  }while(next_permutation(all(s)));
  cout<<s2<<endl;

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
