#include <bits/stdc++.h>
#include <cmath>
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

// int count = 0;
// int rec(int x){
//     if(x>=farthestx&&x>=farthesty)
//         return count;
//     count+=
// }
void solve() {
    int n;
    int l, k;cin>>n>>l>>k;
    int max_d = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        int d = x*x + y*y;
        if (d > max_d) 
            max_d = d;
    }
    int d = floor(sqrt((double)max_d));
    if (d*d < max_d) 
        ++d;
    int count = 0;
    while (l < d) {
        if (l < k) // 3<4 3+4=7, 3*2=6
            l+=k;
        else 
            l<<=1; // l *= 2
        ++count;
    }
    cout<<count<<endl;
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
