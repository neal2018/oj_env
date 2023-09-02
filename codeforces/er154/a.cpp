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
    auto is_prime = [&](int x) {
      for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
      }
      return true;
    };
    [&] {
      for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j <= s.size(); j++) {
          auto t = 10 * (s[i] - '0') + s[j] - '0';
          if (is_prime(t)) {
            cout << t << "\n";
            return;
          }
        }
      }
    }();
  }
}
