// ﷽
// Contest: Educational Codeforces Round 178 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2104/problem/C
// Memory Limit: 512
// Time Limit: 2000
// Start: Mon 28 Apr 2025 07:20:22 PM EEST
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
#define allr(a) (a).rbegin(), (a).rend()
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
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
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

bool beats(int i, int j, int n) {
    if (i == 1 && j == n) return true;
    if (i == n && j == 1) return false;
    return i > j;
}
void solve() {
    int n;cin>>n;
    if(n==2){
        string s;cin>>s;
        if(s=="AB")
            cout<<"Alice"<<endl;
        else 
            cout<<"Bob"<<endl;
        return;
    }
    set<int>a, b;
    for (int i = 0; i < n; i++) {
        char c;cin>>c;
        if(c=='A')a.insert(i+1);
        else b.insert(i+1);
    }
    debug(a);
    debug(b);
    debug("---");
    // magic line
    if((b.size()>1 && b.count(n)) || b.count(1) && b.count(n-1))
    {
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n";
}
int32_t main() {
    /*freopen("whereami.in", "r", stdin);*/
    /*freopen("whereami.out", "w", stdout);*/
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
