#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cout<<g[i][j]<<" ";
  //   }
  //   cout<<'\n';
  // }
  vector<pair<int, int>> right_down{{1, 0}, {0, 1}};
  vector<pair<int, int>> right_down2{{1, 1}, {-1, 1}};
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j]) {
        for (auto& [dx, dy] : right_down) {
          int xx = i + dx, yy = j + dy;
          if (0 <= xx && xx < n && 0 <= yy && yy < m && g[xx][yy]) {
            cnt1++;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j]) {
        for (auto& [dx, dy] : right_down2) {
          int xx = i + dx, yy = j + dy;
          if (0 <= xx && xx < n && 0 <= yy && yy < m && g[xx][yy]) {
            cnt2++;
          }
        }
      }
    }
  }
  cout << cnt1 << '\n';
  cout << cnt2+cnt1 << '\n';
}