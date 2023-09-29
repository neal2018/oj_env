#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    [&] {
      for (int i = 1; i < int(s.size()) / 2; i++) {
        if (s[i - 1] != s[i]) {
          cout << "YES\n";
          return;
        }
      }
      cout << "NO\n";
    }();
  }
}
