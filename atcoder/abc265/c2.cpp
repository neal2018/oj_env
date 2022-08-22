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
  vector<vector<int>> g(n * m);
  vector<int> indeg(n * m), dp(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ii = -1, jj = -1;
      if (a[i][j] == 'U' && i != 0) ii = i - 1, jj = j;
      if (a[i][j] == 'D' && i != n - 1) ii = i + 1, jj = j;
      if (a[i][j] == 'L' && j != 0) ii = i, jj = j - 1;
      if (a[i][j] == 'R' && j != m - 1) ii = i, jj = j + 1;
      if (ii != -1) {
        indeg[ii * n + jj]++;
        g[i * n + j].push_back(ii * n + jj);
      }
    }
  }
  vector<int> q, nq;
  for (int i = 0; i < n * m; i++) {
    if (indeg[i] == 0) q.push_back(i), dp[i] = 1;
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      for (auto& ne : g[node]) {
        indeg[ne]--;
        dp[ne] = max(dp[ne], dp[node] + 1);
        if (indeg[ne] == 0) nq.push_back(ne);
      }
    }
  }
  if (accumulate(indeg.begin(), indeg.end(), 0ll) == 0) {
    cout << *max_element(dp.begin(), dp.end()) << "\n";
  } else {
    cout << "-1\n";
  }
}
