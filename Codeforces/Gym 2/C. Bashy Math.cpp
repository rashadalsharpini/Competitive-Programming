// ﷽
// Contest: Gym 2
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/618821/problem/C
// Memory Limit: 256
// Time Limit: 2500
// Start: 30 يون, 2025 01:51:33 م
//
#include <bits/stdc++.h>
using namespace std;
#ifdef Rashad
// #include "debug.hpp"
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

void solve() {
    int n; cin >> n;
    vi v(n);
    map<int, int> mp;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
        max_val = max(max_val, v[i]);
    }

    int count = 0;
    for (auto &[x, countx] : mp) {
        for (int m = 2 * x; m <= max_val; m += x)
            if (mp.count(m))
                count += 1LL * countx * mp[m];
        count += 1LL * countx * (countx - 1);
    }

    cout << count << endl;
}
int32_t main() {
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
