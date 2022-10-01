#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> p(n - 1);
  for (int i = 1; auto& x : p) cin >> x, x--, g[x].push_back(i), i++;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  function<pair<ll, ll>(int)> dfs = [&](int node) {
    ll sum = 0, leaves = 0;
    for (auto& ne : g[node]) {
      auto [sub_sum, sub_leaves] = dfs(ne);
      sum += sub_sum, leaves += sub_leaves;
    }
    if (leaves == 0) leaves = 1;
    sum += a[node];
    res = max(res, (sum + leaves - 1) / leaves);
    return pair{sum, leaves};
  };
  dfs(0);
  cout << res << "\n";
}
