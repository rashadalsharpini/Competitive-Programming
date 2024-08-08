// ﷽
// Contest: The 2023 ICPC Egyptian Collegiate Programming Contest (Qualifications Day 7)
// Judge: Codeforces
// URL: https://codeforces.com/group/Rilx5irOux/contest/530045/problem/A
// Memory Limit: 64
// Time Limit: 2000
// Start: 28 يول, 2024 09:41:54 ص
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
vll find_b(ll a, ll c) {
    vll possible_b_values;
    ll sqrt_a = sqrt(a);

    for (ll d = 1; d <= sqrt_a; ++d) {
        if (a % d == 0) {
            ll divisor1 = d;
            ll divisor2 = a / d;

            ll b1 = (c * divisor1) / a;
            if ((c * divisor1) % a == 0 && gcd(a, b1) == divisor1) {
                possible_b_values.push_back(b1);
            }

            if (divisor1 != divisor2) {
                ll b2 = (c * divisor2) / a;
                if ((c * divisor2) % a == 0 && gcd(a, b2) == divisor2) {
                    possible_b_values.push_back(b2);
                }
            }
        }
    }
    return possible_b_values;
}
void solve() {
  ll a, c;cin >> a >> c;
  vll result = find_b(a, c);
  /*cout<<result<<endl;*/
  if(result.empty())
    cout<<-1<<endl;
  else
    cout<<*min_element(all(result))<<endl;
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
