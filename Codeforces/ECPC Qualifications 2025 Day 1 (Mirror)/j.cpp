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
const int inf = 1e18;
void solve() {
    int n;cin>>n;
    vi v(n+1);
    int posn;
    for (int i = 1; i <= n; i++) {
        cin>>v[i];
        if(v[i]==n)posn=i;
    }
    int ans = inf;
    auto split = [&](int l, int r) -> int {
        if (r - l + 1 < 2) return inf;

        vi pref(r - l + 2), suff(r - l + 2);
        pref[1] = v[l];
        for (int i = l + 1, j = 2; i <= r; ++i, ++j) {
            pref[j] = max(pref[j - 1], v[i]);
        }

        int len = r - l + 1;
        suff[len] = v[r];
        for (int i = r - 1, j = len - 1; i >= l; --i, --j) {
            suff[j] = max(suff[j + 1], v[i]);
        }

        int res = inf;
        for (int i = 1; i < len; ++i) {
            res = min(res, 1LL * pref[i] + suff[i + 1]);
        }
        return res;
    };
    //first
    if(posn<=n-2)
        ans = min(ans, n+split(posn+1, n));
    //second
    if(posn>1&&posn<n)
        ans = min(ans, n+v[1]+v[n]);
    //thrid
    if(posn>=3)
        ans = min(ans, n+split(1, posn-1));
    cout<<ans<<endl;
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
