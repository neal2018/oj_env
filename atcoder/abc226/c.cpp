#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, x;
  cin >> n;
  vector<ll> t(n);
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> k;
    for (int j = 0; j < k; j++) {
      cin >> x;
      g[i].push_back(x - 1);
    }
  }
  ll res = 0;
  vector<int> seen(n);
  function<void(int)> dfs = [&](int node) {
    if (seen[node]) return;
    res += t[node];
    for (auto& ne : g[node]) dfs(ne);
    seen[node] = 1;
  };
  dfs(n - 1);
  cout << res << '\n';
}