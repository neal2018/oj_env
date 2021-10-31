#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int inf = 1e9;

void solve(int n, int m) {
  vector a(n, vector<int>(m)), lu_min(n, vector<int>(m)), rd_min(n, vector<int>(m)),
      ld_max(n, vector<int>(m)), ru_max(n, vector<int>(m));
  for (auto& s : a)
    for (auto& x : s) cin >> x;
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int x, int y) { return a[x] > a[y]; });
  // lu min
  for (int i = 0; i < n; i++) {
    int cur = inf;
    for (int j = 0; j < m; j++) {
      lu_min[i][j] = cur = min(cur, a[p[i]][j]);
      if (i > 0) lu_min[i][j] = min(lu_min[i - 1][j], cur);
    }
  }
  // rd min
  for (int i = n - 1; i >= 0; i--) {
    int cur = inf;
    for (int j = m - 1; j >= 0; j--) {
      rd_min[i][j] = cur = min(cur, a[p[i]][j]);
      if (i < n - 1) rd_min[i][j] = min(rd_min[i + 1][j], cur);
    }
  }
  // ld max
  for (int i = n - 1; i >= 0; i--) {
    int cur = 0;
    for (int j = 0; j < m; j++) {
      ld_max[i][j] = cur = max(cur, a[p[i]][j]);
      if (i < n - 1) ld_max[i][j] = max(ld_max[i + 1][j], cur);
    }
  }
  // ru max
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = m - 1; j >= 0; j--) {
      ru_max[i][j] = cur = max(cur, a[p[i]][j]);
      if (i > 0) ru_max[i][j] = max(ru_max[i - 1][j], cur);
    }
  }
  // res, (i-1, j-1) to (i, j)
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (lu_min[i - 1][j - 1] > ld_max[i][j - 1] && ru_max[i - 1][j] < rd_min[i][j]) {
        cout << "YES\n";
        string res(n, 'B');
        for (int k = 0; k < i; k++) res[p[k]] = 'R';
        cout << res << ' ' << j << '\n';
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    solve(n, m);
  }
}