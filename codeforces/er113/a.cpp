#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    [&] {
      for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i; j < n; j++) {
          c += (s[j] == 'a' ? 1 : -1);
          if (c == 0) {
            cout << i + 1 << " " << j + 1 << "\n";
            return;
          }
        }
      }
      cout << "-1 -1\n";
    }();
  }
}
