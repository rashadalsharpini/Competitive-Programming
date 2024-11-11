// ﷽
// Contest: Sheet #4 (Strings)
// Judge: Codeforces
// URL: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/S
// Memory Limit: 256
// Time Limit: 1000
// Start: 07 نوف, 2024 10:24:16 ص
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
  string s;
  cin >> s;
  vector<string> groups;
  string current_group;
  int countL = 0, countR = 0;

  for (char c : s) {
    current_group += c;
    if (c == 'R') countR++;
    else countL++;

    if (countR == countL) {
      groups.push_back(current_group);
      current_group.clear();
      countR = countL = 0;
    }
  }

  cout << groups.size() << endl;
  for (const string& group : groups) {
    cout << group << endl;
  }
}
void solve2(){
  string s; 
  cin >> s; 
  int countL = 0, countR = 0, groupCount = 0; 
  int groupEndIndices[500]; 
  int groupIndex = 0; 
  for (int i = 0; i < s.size(); i++) { 
    if (s[i] == 'L') 
      countL++; 
    else if (s[i] == 'R') 
      countR++; 

    if (countL == countR) { 
      groupCount++; 
      groupEndIndices[groupIndex] = i; 
      groupIndex++; 
    } 
  } 

  cout << groupCount <<endl; 

  int i = 0; 
  for (int j = 0; j < groupIndex; j++) { 
    while (i <= groupEndIndices[j]) { 
      cout << s[i]; 
      i++; 
    } 
    cout << endl;
    i = groupEndIndices[j] + 1;
  } 
}
int32_t main() {
  /*freopen("whereami.in", "r", stdin);*/
  /*freopen("whereami.out", "w", stdout);*/
  fastio
    int t = 1;
  /*cin>>t;*/
  while (t--)
    solve2();
  return 0;
}
