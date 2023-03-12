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
    if (a[0] == b[0]) {
      cout << "YES\n";
      cout << a[0] << "*\n";
      continue;
    }
    if (a.back() == b.back()) {
      cout << "YES\n";
      cout << "*" << a.back() << "\n";
      continue;
    }
    [&] {
      for (int i = 0; i < int(a.size()) - 1; i++) {
        auto t = a.substr(i, 2);
        if (b.find(t) != string::npos) {
          cout << "YES\n";
          cout << "*" << t << "*\n";
          return;
        }
      }
      cout << "NO\n";
    }();
  }
}
