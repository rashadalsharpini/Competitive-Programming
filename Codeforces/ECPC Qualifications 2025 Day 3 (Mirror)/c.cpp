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

void solve() {
    int n, m;cin>>n>>m;
    vi v(n);cin>>v;
    vi w(m);cin>>w;
    for(int i = 0; i < m; i++) {
        w[i]--;
    }
    w.push_back(-1);
    w.push_back(n-1);
    sort(all(w));
    m+=2;
    int cost=0;
    int maxSaving=0;
    for(int i = 0; i < m-1; i++) {
        set<int> seg;
        for(int x = w[i]+1; x <= w[i+1]; x++) {
            seg.insert(v[x]);
        }
        cost += seg.size();
    }
    for (int i = 1; i < m-2; i++) {
        set<int> seg1, seg2, merge;
        for (int x = w[i-1]+1; x <= w[i]; x++) {
            seg1.insert(v[x]);
            merge.insert(v[x]);
        }
        for (int x = w[i]+1; x <= w[i+1]; x++) {
            seg2.insert(v[x]);
            merge.insert(v[x]);
        }
        int saving = seg1.size()+seg2.size()-merge.size();
        maxSaving = max(maxSaving, saving);
    }
    cout<<cost-maxSaving<<endl;
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
