//C++ program to perform spiral order 
//https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
// traversal of a matrix
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
    for (T &x : data) input >> x;
    return input;
}
template <typename T> ostream &operator<<(ostream &output, const vector<T> &data) {
    for (const T &x : data) output << x << ' ';
    return output;
}
const int MOD = 1e9+7;

vi spirallyTraverse(vector<vi>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vi res;
    vector<vector<bool> > vis(m, vector<bool>(n, false));

    // Arrays to represent the changes in row and column indices: 
  	// move right(0, +1), move down(+1, 0), 
  	// move left(0, -1), move  up(-1, 0)
  
    // Change in row index for each direction
    vi dr = { 0, 1, 0, -1 };

    // Change in column index for each direction
    vi dc = { 1, 0, -1, 0 };

    // Initial position in the matrix
    int r = 0, c = 0;

    // Initial direction index (0 corresponds to 'right')
    int idx = 0;

    for (int i = 0; i < m * n; ++i) {
        res.push_back(mat[r][c]);
        vis[r][c] = true;

        // Calculate the next cell coordinates based on
        // current direction
        int newR = r + dr[idx];
        int newC = c + dc[idx];

        // Check if the next cell is within bounds and not
        // visited
        if (0 <= newR && newR < m && 0 <= newC && newC < n
            && !vis[newR][newC]) {

            // Move to the next row
            r = newR;

            // Move to the next column
            c = newC;
        }
        else {

            // Change direction (turn clockwise)
            idx = (idx + 1) % 4;

            // Move to the next row according to new
            // direction
            r += dr[idx];

            // Move to the next column according to new
            // direction
            c += dc[idx];
        }
    }
  
    return res;
}
void solve() {
    int n, m;cin>>n>>m;
    vector<vi> mat(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>mat[i][j];

    vi res = spirallyTraverse(mat);

    for (int i : res)
        cout << i << " ";
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
