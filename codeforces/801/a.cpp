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
    vector a(n, vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    int x = 0, y = 0;
    for (auto i : views::iota(0, n)) {
      for (auto j : views::iota(0, m)) {
        if (a[i][j] > a[x][y]) {
          x = i, y = j;
        }
      }
    }
    cout << (max(x + 1, n - x)) * (max(y + 1, m - y)) + 1 << "\n";
  }
}
