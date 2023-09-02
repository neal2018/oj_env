#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string a, b;
    cin >> a >> b;
    if ([&] {
          if (a[0] != b[0]) return false;
          if (a.back() != b.back()) return false;
          if (a[0] == a.back()) return true;
          for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] == a[0] && a[i + 1] == a.back() && b[i] == b[0] && b[i + 1] == b.back())
              return true;
          }
          return false;
        }()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
