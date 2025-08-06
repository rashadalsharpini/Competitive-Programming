#include <bits/stdc++.h>
#include <bitset>
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

const string s1 = "0101010101010101010101010101010101010101010101010101010101010101";
const string s2 = "1010101010101010101010101010101010101010101010101010101010101010";
void solve() {//our idea
    int n, l;cin>>n>>l;
    bitset<64> num(l);
    string numst = num.to_string();
    const auto pos = numst.find_first_not_of('0');
    numst = numst.substr(pos);
    set<int> nums;
    int sz = numst.size();
    while(sz>=2){
        string dump1, dump2;
        for (int i = 0; i < sz; i++) {
            dump1.push_back(s1[i]);
            dump2.push_back(s2[i]);
        }
        bitset<64> val1(dump1);
        bitset<64> val2(dump2);
        int dump3 = val1.to_ullong();
        if(dump3>1&&dump3<=l)
            nums.insert(dump3);
        dump3 = val2.to_ullong();
        if(dump3>1&&dump3<=l)
            nums.insert(dump3);
        sz--;
    }
    cout<<(nums.size()>=n?"YES":"NO")<<endl;
}

void solve2(){ //https://youtu.be/dM5RyIHXEeA?si=OkIPj9xVfmn5IFR0
    int n,l;cin>>n>>l;
    int x = 2;
    for (int i = 0; i < n; i++) {
        if(x>l){
            cout << "NO" << endl;
            return;
        }
        int add = (x&1ll);
        x<<=1ll;
        if(!add)x++;
    }
    cout << "YES" << endl;
}
int32_t main() {
    /*freopen("whereami.in", "r", stdin);*/
    /*freopen("whereami.out", "w", stdout);*/
    fastio
    int t = 1;
    cin>>t;
    while (t--)
        solve2();
    return 0;
}
