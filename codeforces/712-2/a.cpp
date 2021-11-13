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
    int f = 1;
    for (int i = 0, j = (int)s.size() - 1; i <= j && f; i++, j--) {
      if (s[j] != 'a') {
        s.insert(s.begin() + i, 'a');
        f = 0;
      } else if (s[i] != 'a') {
        s.insert(s.begin() + j, 'a');
        f = 0;
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << s << '\n';
    }
  }
}