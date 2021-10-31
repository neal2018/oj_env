#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, u, v;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<ll> cnt(n), sum(n), res(n);  // for child
  function<void(ll, ll)> dfs = [&](ll node, ll fa) {
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      sum[node] += sum[ne] + cnt[ne] + 1;
      cnt[node] += cnt[ne] + 1;
    }
    return;
  };
  dfs(0, -1);
  function<void(ll, ll)> dfs2 = [&](ll node, ll fa) {
    if (fa == -1) {
      res[node] = sum[node];
    } else {
      res[node] = res[fa] + cnt[0] - 2 * cnt[node] - 1;
    }
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs2(ne, node);
    }
    return;
  };
  dfs2(0, -1);
  for (auto& x : res) {
    cout << x << '\n';
  }
}