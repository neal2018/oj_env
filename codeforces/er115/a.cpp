#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  string s1, s2;
  while (T--) {
    cin >> n >> s1 >> s2;
    int f = 1;
    for (int i = 0; i < n && f; i++) {
      if (s1[i] == s2[i] && s1[i] == '1') {
        cout << "NO\n";
        f = 0;
        break;
      }
    }
    if (!f) continue;
    cout << "YES\n";
  }
}