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
    int n = int(s.size()), total = 0;
    [&] {
      for (int i = 0; i < n; i++) {
        auto c = (s[i] - '0') ^ (i & 1);
        total += 2 * c - 1;
        if (abs(total) > n - i - 1) {
          cout << i + 1 << "\n";
          return;
        }
      }
      cout << "-1\n";
    }();
  }
}