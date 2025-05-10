// ﷽
// Contest: Educational Codeforces Round 52 (Rated for Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/problemset/problem/1065/B
// Memory Limit: 256
// Time Limit: 1000
// Start: Fri 09 May 2025 10:03:15 PM EEST
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

void solve() {
    int n, m;cin >> n >> m;

    // Minimum isolated vertices: spread edges as much as possible
    int min_isolated = max(0LL, n - 2 * m);

    // Maximum isolated vertices: use binary search to find minimal k such that k*(k-1)/2 >= m
    int left = 0, right = n, k = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        int edges = mid * (mid - 1) / 2;
        if (edges >= m) {
            k = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    int max_isolated = n - k;

    cout << min_isolated << " " << max_isolated << endl;
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
