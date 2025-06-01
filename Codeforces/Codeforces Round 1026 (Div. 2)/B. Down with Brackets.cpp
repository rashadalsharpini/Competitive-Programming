// ﷽
// Contest: Codeforces Round 1026 (Div. 2)
// Judge: Codeforces
// URL: https://codeforces.com/contest/2110/problem/B
// Memory Limit: 256
// Time Limit: 1000
// Start: Sat 24 May 2025 06:13:28 PM EEST
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

bool isBalanced(string& s){
    int count = 0;
    for(char c:s){
        if(c=='(')count++;
        else{
            if(count==0)return false;
            count--;
        }
    }
    return count ==0;
}
void solve() {
    string s;cin>>s;
    s=s.substr(1, s.size()-2);
    cout << (isBalanced(s)?"NO":"YES")<< endl;
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
