// ﷽
// Contest: Gym 5
// Judge: Codeforces
// URL: https://codeforces.com/group/2QN7VVtg4T/contest/620739/problem/B
// Memory Limit: 256
// Time Limit: 2000
// Start: 12 يول, 2025 06:22:58 م
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
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    unordered_set<string> files;
    files.reserve(N * 2);

    string output;
    output.reserve(N * 3);

    for(int i = 0; i < N; i++){
        getline(cin, line);
        if (line[0] == 't') {
            string fname = line.substr(6);
            files.insert(move(fname));
        }
        else if (line[0] == 'r') {
            string fname = line.substr(3);
            files.erase(fname);
        }
        else {
            output += to_string(files.size());
            output += endl;
        }
    }
    cout << output;
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
