#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    [&] {
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[0]) {
          cout << 2 * s.size() - i << '\n';
          return;
        }
      }
      cout << s.size() - 1 << "\n";
    }();
  }
}
