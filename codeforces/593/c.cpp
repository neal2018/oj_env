#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  int cur = 1;
  for (int j = 0; j < n; j++) {
    if (j % 2 == 0) {
      for (int i = 0; i < n; i++) a[i][j] = cur++;
    } else {
      for (int i = n - 1; i >= 0; i--) a[i][j] = cur++;
    }
  }
  for (auto& r : a) {
    for (auto& x : r) cout << x << " ";
    cout << "\n";
  }
}
