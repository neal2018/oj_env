#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> edges(m);
    for (int i = 0, u, v; i < m; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), edges[i] = {u, v};
    }
    int cnt = 0, now = 0;
    vector<ll> dfn(n, -1), low(n), belong(n, -1), stk;
    function<void(ll)> tarjan = [&](ll node) {
      dfn[node] = low[node] = now++, stk.push_back(node);
      for (auto& ne : g[node]) {
        if (dfn[ne] == -1) {
          tarjan(ne);
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
      if (dfn[i] == -1) tarjan(i);
    }
    // for (auto& x : belong) cout << x << ' ';
    // cout << "\n";
    if (cnt == 1) {
      cout << "0\n";
      continue;
    }
    vector<int> in(cnt), out(cnt);
    for (auto& [u, v] : edges) {
      if (belong[u] != belong[v]) {
        out[belong[u]]++, in[belong[v]]++;
      }
    }
    int in_cnt = 0, out_cnt = 0;
    for (int i = 0; i < cnt; i++) {
      in_cnt += (in[i] == 0);
      out_cnt += (out[i] == 0);
    }
    cout << max(in_cnt, out_cnt) << "\n";
  }
}