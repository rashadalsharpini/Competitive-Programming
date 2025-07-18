// ﷽
// Contest: Gym 9
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/622926/problem/B
// Memory Limit: 1024
// Time Limit: 1000
// Start: 18 يول, 2025 04:05:54 م
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
bool isPrime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

const int MAXN = 10000000;
vector<bool> isprime(MAXN+1, true);
vi cnt(MAXN+1, 0);
void solve() {
    int n;cin>>n;
    if(!isprime[n]){
        cout << "NO" << endl;
        return;
    }
    while(n>2){
        n = cnt[n-1];
        if(!isprime[n]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}
int32_t main() {
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    fastio
    isprime[0] = isprime[1] = false;
    for (int i = 2; i * i <= MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i * i; j <= MAXN; j += i)
            isprime[j] = false;
    }
    for (int i = 1; i <= MAXN; i++) {
        cnt[i] = cnt[i-1] + (isprime[i] ? 1 : 0);
    }
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
