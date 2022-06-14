#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> pre(n), in(n);
  for (auto& x : pre) cin >> x, x--;
  for (auto& x : in) cin >> x, x--;
  if (pre[0] != 0) {
    cout << "-1\n";
    return 0;
  }
  vector<int> id_in(n);
  for (int i = 0; i < n; i++) id_in[in[i]] = i;
  int cur = 0;
  vector<pair<int, int>> tree(n, {-1, -1});
  function<int(int, int)> dfs = [&](int l, int r) {
    if (l == r) return -1;
    int node = pre[cur];
    cur++;
    int id = id_in[node];
    if (id < l || id >= r) {
      cout << "-1\n";
      exit(0);
    }
    tree[node].first = dfs(l, id);
    tree[node].second = dfs(id + 1, r);
    return node;
  };
  dfs(0, n);
  for (auto& [l, r] : tree) cout << l + 1 << " " << r + 1 << "\n";
}
