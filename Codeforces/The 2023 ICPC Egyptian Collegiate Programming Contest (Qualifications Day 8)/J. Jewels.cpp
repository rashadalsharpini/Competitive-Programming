// ﷽
// Contest: The 2023 ICPC Egyptian Collegiate Programming Contest (Qualifications Day 8)
// Judge: Codeforces
// Url: https://codeforces.com/group/Rilx5irOux/contest/530044/problem/J
// Memory limit: 256
// Time limit: 1000
// Start: 25 يول, 2025 06:05:14 م
//
#include <bits/stdc++.h>
using namespace std;
#ifdef rashad
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
    int n, l, r;
    cin >> n >> l >> r;
    vi v(n);cin>>v;
    int cur = l;
    for (int i = 0; i < n && cur <= r; i++)
        if (v[i] == cur)
            cur++;
    cout<<(cur>r?"YES":"NO")<<endl;
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
