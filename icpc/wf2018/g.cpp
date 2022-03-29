#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  vector<array<int, 2>> b(n);
  vector<int> deg_a(n);
  vector<int> deg_b(n);
  for (auto& [x, y] : a) {
    cin >> x >> y, x--, y--;
    if (x != -1) deg_a[x]++;
    if (y != -1) deg_a[y]++;
  }
  for (auto& [x, y] : b) {
    cin >> x >> y, x--, y--;
    if (x != -1) deg_b[x]++;
    if (y != -1) deg_b[y]++;
  }
  int ra = 0;
  for (int i = 0; i < n; i++) {
    if (deg_a[i] == 0) ra = i;
  }
  int rb = 0;
  for (int i = 0; i < n; i++) {
    if (deg_b[i] == 0) rb = i;
  }
  int diff_a = -1, diff_b = -1;
  function<bool(int, int)> dfs = [&](int x, int y) {
    if (x == -1 || y == -1) return true;
    if (x != y) {
      diff_a = x, diff_b = y;
      return false;
    }
    if (dfs(a[x][0], b[y][0])) {
      return dfs(a[x][1], b[y][1]);
    } else {
      return false;
    }
  };
  dfs(ra, rb);
  if (diff_a == -1) {
    cout << 0 << "\n";
    return 0;
  }
  cout << 1 << "\n";
  if (b[diff_b][0] == diff_a) {
    cout << b[diff_b][0] + 1 << "\n";
  } else {
    cout << b[diff_b][1] + 1 << "\n";
  }
}