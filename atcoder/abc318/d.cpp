#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector d(n + 1, vector<ll>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1, x; j < n; j++) {
      cin >> x;
      d[i][j] = d[j][i] = x;
    }
  }
  if (n % 2 == 1) n++;
  vector<int> match(n, -1);
  ll res = 0;
  function<void(int)> dfs = [&](int i) {
    if (i == n) {
      ll cur = 0;
      for (int t = 0; t < n; t++) {
        cur += d[t][match[t]];
      }
      res = max(res, cur);
      return;
    }
    if (match[i] != -1) {
      dfs(i + 1);
      return;
    }
    for (int t = i + 1; t < n; t++) {
      if (match[t] != -1) continue;
      match[t] = i;
      match[i] = t;
      dfs(i + 1);
      match[i] = -1;
      match[t] = -1;
    }
  };
  dfs(0);
  cout << (res / 2) << "\n";
}
