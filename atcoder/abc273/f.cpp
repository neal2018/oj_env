#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  for (auto& v : a) {
    for (auto& x : v) {
      cin >> x;
    }
  }
  vector cnt(n, vector<map<int, ll>>(n));
  function<void(int, int, int, int)> dfs = [&](int i, int j, int t, int cur) {
    cur ^= a[i][j];
    if (t == 0) {
      cnt[i][j][cur]++;
      return;
    }
    for (auto& [di, dj] : {pair{1, 0}, pair{0, 1}}) {
      dfs(i + di, j + dj, t - 1, cur);
    }
  };
  dfs(0, 0, n - 1, 0);
  ll res = 0;
  function<void(int, int, int, int)> dfs2 = [&](int i, int j, int t, int cur) {
    if (t == 0) {
      res += cnt[i][j][cur];
      return;
    }
    cur ^= a[i][j];
    for (auto& [di, dj] : {pair{-1, 0}, pair{0, -1}}) {
      dfs2(i + di, j + dj, t - 1, cur);
    }
  };
  dfs2(n - 1, n - 1, n - 1, 0);
  cout << res << "\n";
}
