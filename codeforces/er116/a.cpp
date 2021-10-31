#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  string s;
  cin >> T;
  while (T--) {
    cin >> s;
    int ab = 0, ba = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b') ab++;
      if (s[i] == 'b' && s[i + 1] == 'a') ba++;
    }
    if (ab == ba) {
      cout << s << '\n';
    } else {
      s[0] = (s[0] == 'a' ? 'b' : 'a');
      cout << s << '\n';
    }
    // {
    //   int ab = 0, ba = 0;
    //   for (int i = 0; i < s.size() - 1; i++) {
    //     if (s[i] == 'a' && s[i + 1] == 'b') ab++;
    //     if (s[i] == 'b' && s[i + 1] == 'a') ba++;
    //   }
    //   cout<<ab<<" "<<ba<<endl;
    // }
  }
}