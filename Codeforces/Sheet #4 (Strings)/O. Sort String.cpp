#include<iostream>
using namespace std;
#define fastio                                                               \
  ios_base::sync_with_stdio(false);                                            \
cin.tie(NULL);

void solve() {
  int size;
  cin >> size;
  int arr[26] = {};

  for (int i = 0; i < size; i++) {
    char s;
    cin >> s;
    if (s >= 'a' && s <= 'z') {  
      arr[s - 'a']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    while (arr[i]--) {
      cout.put(i + 'a');
    }
  }

  cout.put('\n');  
  cout.flush();    
}
int32_t main() {
  fastio
    solve();
  return 0;
}
