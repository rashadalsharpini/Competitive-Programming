// ﷽
// Contest: ECPC Qualifications 2024 Day 4 (Mirror)
// Judge: Codeforces
// URL: https://codeforces.com/group/Rilx5irOux/contest/538098/problem/J
// Memory Limit: 256
// Time Limit: 2000
// Start: 24 يول, 2025 08:14:36 م
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
    int n;
    cin >> n;

    vector<tuple<int, int, int, int>> rects;
    set<int> xs, ys;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rects.emplace_back(x1, y1, x2, y2);
        xs.insert(x1);
        xs.insert(x2);
        ys.insert(y1);
        ys.insert(y2);
    }

    vector<int> cx(xs.begin(), xs.end());
    vector<int> cy(ys.begin(), ys.end());
    unordered_map<int, int> x_map, y_map;
    for (int i = 0; i < cx.size(); ++i) x_map[cx[i]] = i;
    for (int i = 0; i < cy.size(); ++i) y_map[cy[i]] = i;

    int xn = cx.size();
    int yn = cy.size();
    vector<vector<int>> grid(xn + 2, vector<int>(yn + 2, 0));

    for (auto &[x1, y1, x2, y2] : rects) {
        int xi1 = x_map[x1];
        int yi1 = y_map[y1];
        int xi2 = x_map[x2];
        int yi2 = y_map[y2];

        grid[xi1][yi1] += 1;
        grid[xi2][yi2] += 1;
        grid[xi1][yi2] -= 1;
        grid[xi2][yi1] -= 1;
    }

    vector<vector<int>> ps(xn + 2, vector<int>(yn + 2, 0));
    for (int i = 0; i < xn; ++i) {
        for (int j = 0; j < yn; ++j) {
            ps[i][j] = grid[i][j];
            if (i > 0) ps[i][j] += ps[i - 1][j];
            if (j > 0) ps[i][j] += ps[i][j - 1];
            if (i > 0 && j > 0) ps[i][j] -= ps[i - 1][j - 1];
        }
    }

    int max_overlap = 0;
    for (int i = 0; i < xn; ++i)
        for (int j = 0; j < yn; ++j)
            max_overlap = max(max_overlap, ps[i][j]);

    cout<<max_overlap<<endl;


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
