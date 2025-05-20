// ﷽
// Contest: Educational Codeforces Round 178 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2104/problem/D
// Memory Limit: 512
// Time Limit: 2000
// Start: Mon 19 May 2025 09:05:23 PM EEST
//
#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#ifdef Rashad
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

#define int long long
#define double long double
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define f first
#define s second
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
// 48 - 57 -> 0 - 9  65 - 90 -> A-Z 97 - 122 -> a-z


const int MAX = 7e6;
vector<bool> is_prime(MAX,true);
vi primes, prefPrime(MAX, 0);
void sieve(vector<bool> &is_prime) {
    is_prime[1] = false;
    is_prime[0] = false;
    for (int i = 4; i < MAX; i += 2)
        is_prime[i] = false;
    for (int i = 3; i * i < MAX; i += 2)
        if (is_prime[i])
            for (int j = i * i; j < MAX; j += i * 2)
                is_prime[j] = false;
    for (int i = 0; i < is_prime.size(); i++)
        if(is_prime[i])
            primes.push_back(i);
}

bool isIdeal(vi& v, int n){
    if(n<2) return true;
    for (int i = 0; i < n; i++)
        if(v[i]<2) return false;
    for (int i = 0; i < n; i++) 
        for (int j = i+1; j < n; j++) 
            if(v[i]!=v[j])
                if(gcd(v[i], v[j]) != 1)return false;
    return true;
}
void solve() {
    int n;cin>>n;
    vi v(n);cin>>v;
    sort(allr(v));
    vi pref(n+1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + v[i-1];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(pref[i] >= prefPrime[i])
            ans = i;
        else 
            break;
    }
    cout<<n-ans<<endl;
}
int32_t main() {
    /*freopen("whereami.in", "r", stdin);*/
    /*freopen("whereami.out", "w", stdout);*/
    fastio
    sieve(is_prime);
    for (int i = 1; i < primes.size(); i++) 
        prefPrime[i] = prefPrime[i-1] + primes[i-1];
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
