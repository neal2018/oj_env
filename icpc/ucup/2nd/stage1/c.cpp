#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<tuple<string, int, int>> a(n);
    for (auto& [s, x, y] : a) {
      cin >> s >> x;
      if (s == "add") {
        y = -1;
      } else {
        cin >> y, y--;
      }
    }
    constexpr int MOD = 256;
    [&] {
      vector<int> seen(n * 256 + 256);
      for (int i = 0, r = 0; i < n;) {
        auto [s, v, k] = a[i];
        if (seen[i * 256 + r]) {
          cout << "No\n";
          return;
        }
        seen[i * 256 + r] = 1;
        if (s == "add") {
          r = (r + v) % MOD;
          i++;
        } else if (s == "beq") {
          if (r == v) {
            i = k;
          } else {
            i++;
          }
        } else if (s == "bne") {
          if (r != v) {
            i = k;
          } else {
            i++;
          }
        } else if (s == "blt") {
          if (r < v) {
            i = k;
          } else {
            i++;
          }
        } else {
          if (r > v) {
            i = k;
          } else {
            i++;
          }
        }
      }
      cout << "Yes\n";
    }();
  }
}
