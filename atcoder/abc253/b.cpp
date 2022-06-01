#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<pair<int, int>> pos;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'o') {
        pos.push_back({i, j});
      }
    }
  }
  cout << abs(pos[0].first - pos[1].first) + abs(pos[0].second - pos[1].second) << "\n";
}
