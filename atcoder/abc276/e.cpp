#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> g(n * m);
  int s = 0;
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') s = m * i + j;
      if (a[i][j] != '#') {
        for (auto& [di, dj] : directions) {
          int ii = i + di, jj = j + dj;
          if (0 <= ii && ii < n && 0 <= jj && jj < m) {
            if (a[ii][jj] != '#') {
              g[i * m + j].push_back(ii * m + jj);
              g[ii * m + jj].push_back(i * m + j);
            }
          }
        }
      }
    }
  }
  n = n * m;
  int cnt = 0, now = 0;
  vector<int> dfn(n, -1), low(n), belong(n, -1), stk;
  function<void(int, int)> tarjan = [&](int node, ll fa) {
    dfn[node] = low[node] = now++, stk.push_back(node);
    for (auto& ne : g[node]) {
      if (ne == fa) continue;  // remove if directed
      if (dfn[ne] == -1) {
        tarjan(ne, node);
        low[node] = min(low[node], low[ne]);
      } else if (belong[ne] == -1) {
        low[node] = min(low[node], dfn[ne]);
      }
    }
    if (dfn[node] == low[node]) {
      while (true) {
        auto v = stk.back();
        belong[v] = cnt;
        stk.pop_back();
        if (v == node) break;
      }
      ++cnt;
    }
  };

  for (int i = 0; i < n; i++) {
    if (dfn[i] == -1) tarjan(i, -1);
  }

  vector<int> freq(cnt);
  for (auto& x : belong) freq[x]++;

  if (freq[belong[s]] > 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
