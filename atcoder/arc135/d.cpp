#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  n *= 2;
  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> a[i][j], a[j][i] = a[i][j];
    }
  }
  vector<int> nex(n + 1, -1), pre(n + 1, -1);
  // sentinel: n
  for (int i = 1; i < n + 1; i++) pre[i] = i - 1;
  for (int i = 0; i < n; i++) nex[i] = i + 1;
  pre[0] = n, nex[n] = 0;
  ll res = 0;
  function<void(ll, ll)> dfs = [&](ll cur, ll mini) {
    if (nex[n] == n) {
      res = max(res, cur);
      return;
    }
    int i = nex[n];
    if (i < n) {
      for (int j = nex[i]; j != n; j = nex[j]) {
        nex[pre[i]] = nex[i], pre[nex[i]] = pre[i];
        nex[pre[j]] = nex[j], pre[nex[j]] = pre[j];
        dfs(cur ^ a[i][j], i + 1);
        nex[pre[i]] = i, pre[nex[i]] = i;
        nex[pre[j]] = j, pre[nex[j]] = j;
      }
    }
  };
  dfs(0, 0);
  cout << res << "\n";
}
