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
    map<int, int> col, row;
    for (int i = 0; i < 3; i++) {
      int x, y;
      cin >> x >> y;
      row[x]++, col[y]++;
    }
    auto get = [&](map<int, int>& t, int need) {
      for (auto& [k, v] : t) {
        if (v == need) return k;
      }
      return -1;
    };
    int tx = get(row, 1);
    int ty = get(col, 1);
    int cx = get(row, 2);
    int cy = get(col, 2);
    int x, y;
    cin >> x >> y;
    if (!((cx == n || cx == 1) && (cy == n || cy == 1))) {
      if (abs(tx - x) % 2 == 0 && abs(ty - y) % 2 == 0) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    } else {
      if (x == cx || y == cy) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
