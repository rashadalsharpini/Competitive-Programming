// ﷽
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2217
// Memory Limit: 512
// Time Limit: 1000
// Start: 02 أكت, 2024 04:45:44 م
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
const int maxN = 2e5+5;

int N, M, cnt, x[maxN], pos[maxN];

void update(int a, int b){
  if(pos[x[a]-1] <= pos[x[a]] && b < pos[x[a]-1]) cnt++;
  if(pos[x[a]-1] > pos[x[a]] && b >= pos[x[a]-1]) cnt--;
  if(pos[x[a]+1] >= pos[x[a]] && b > pos[x[a]+1]) cnt++;
  if(pos[x[a]+1] < pos[x[a]] && b <= pos[x[a]+1]) cnt--;
  pos[x[a]] = b;

  if(pos[x[b]-1] <= pos[x[b]] && a < pos[x[b]-1]) cnt++;
  if(pos[x[b]-1] > pos[x[b]] && a >= pos[x[b]-1]) cnt--;
  if(pos[x[b]+1] >= pos[x[b]] && a > pos[x[b]+1]) cnt++;
  if(pos[x[b]+1] < pos[x[b]] && a <= pos[x[b]+1]) cnt--;
  pos[x[b]] = a;

  swap(x[a], x[b]);
}
void solve(){
  cin>>N>>M;
  for(int i=1;i<=N;++i){
    cin>>x[i];
    pos[x[i]]=i;
  }
  pos[N+1]=N+1;
  cnt=1;
  for(int i = 1, ptr = 0; i <= N; i++){
    if(ptr > pos[i])
      cnt++;
    ptr = pos[i];
  }
  for(int i=0,a,b;i<M;++i){
    cin>>a>>b;
    update(a, b);
    cout<<cnt<<endl;
  }
}

int32_t main() {
  /*freopen("whereami.in", "r", stdin);*/
  /*freopen("whereami.out", "w", stdout);*/
  fastio
    int t = 1;
  /*cin>>t;*/
  while (t--)
    solve();
  return 0;
}
