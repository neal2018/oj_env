#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int left = -n - m, right = -n - m, up = -n - m, down = -n - m;
    for (auto i : views::iota(0, n)) {
      for (char c; auto j : views::iota(0, m)) {
        cin >> c;
        if (c == 'B') {
          left = max(left, i - j), right = max(right, i + j);
          up = max(up, -i + j), down = max(down, -i - j);
        }
      }
    }
    int x = -1, y = -1, res = 1e9;
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        int cost = max({left - (i - j), right - (i + j), up - (-i + j), down - (-i - j)});
        if (cost < res) res = cost, x = i, y = j;
      }
    }
    cout << x + 1 << " " << y + 1 << "\n";
  }
}
