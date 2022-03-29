#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m;
  cin >> n >> m;
  vector<ll> deg(n);
  vector<vector<ll>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, deg[u]++, deg[v]++;
  }
  vector<pair<ll, ll>> nodes(n);
  for (int i = 0; i < n; i++) nodes[i] = {deg[i], i};
  ll need = accumulate(deg.begin(), deg.end(), 0ll) - (2 * n - 2);
  sort(nodes.begin(), nodes.end(), greater<>());
  ll res = 0;
  for (auto& [d, i] : nodes) {
    ll minus = min(need, d - 1);
    d -= minus, need -= minus;
    if (minus) res++;
  }
  cout << res << "\n" << n << " " << n - 1 << "\n";
  vector<ll> leaves;
  sort(nodes.begin(), nodes.end());
  for (int ii = 0; ii < n; ii++) {
    auto& [d, i] = nodes[ii];
    if (d > 1 || ii == n - 1) {
      for (; d > (ii < n - 1); d--, leaves.pop_back()) {
        cout << i << " " << leaves.back() << "\n";
      }
    }
    leaves.push_back(i);
  }
}
