// ﷽
// Contest: Gym 5
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/620739/problem/L
// Memory Limit: 256
// Time Limit: 2500
// Start: 13 يول, 2025 11:54:56 م
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
    int n, c;
    cin >> n >> c;
    vector<double> a(n);
    for(auto &x : a) 
    cin >> x;

    // 1) Compute sum of beauties
    double S = accumulate(a.begin(), a.end(), 0.0);

    // 2) Sort descending
    sort(a.begin(), a.end(), greater<>());

    // 3) We cannot buy more than 100 per type, so at most 100*n total flowers
    int maxFlowers = min(c, 100LL * n);

    // 4) Greedily buy from the highest-beauty types
    double sumBeauty = 0.0;
    int rem = maxFlowers;
    for(int i = 0; i < n && rem > 0; i++){
        int take = min(100LL, rem);
        sumBeauty += a[i] * take;
        rem -= take;
    }

    // 5) Compute and output the final beauty
    double answer = sumBeauty / S;
    cout << fixed << setprecision(15) << answer <<endl;
}
int32_t main() {
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
