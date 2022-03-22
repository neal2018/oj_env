#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  auto compress = a;
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  for (auto& x : a) x = lower_bound(compress.begin(), compress.end(), x) - compress.begin();
  vector<int> total(compress.size()), cnt(compress.size());
  for (auto& x : a) total[x]++;
  vector<int> in(n), out(n), tag(n + 1);
  int cur = 0;
  function<void(int, int)> dfs = [&](int node, int fa) {
    in[node] = cur++;
    int bak = cnt[a[node]];
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      int before = cnt[a[node]];
      dfs(ne, node);
      if (cnt[a[node]] - before > 0) {
        tag[0]++, tag[n]--;
        tag[in[ne]]--, tag[out[ne]]++;
      }
    }
    out[node] = cur;
    cnt[a[node]]++;
    if (cnt[a[node]] - bak < total[a[node]]) {
      tag[in[node]]++, tag[out[node]]--;
    }
  };
  dfs(0, -1);
  vector<int> sum(n);
  sum[0] = tag[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + tag[i];
  int res = accumulate(sum.begin(), sum.end(), 0, [](int x, int y) { return x + (y == 0); });
  cout << res << "\n";
}
