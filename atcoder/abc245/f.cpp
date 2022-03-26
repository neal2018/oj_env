#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n);
  vector<pair<ll, ll>> edges(m);
  for (auto& [u, v] : edges) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v);
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
    if (belong[i] == -1) tarjan(i);
  }
  vector<ll> total(cnt);
  for (int i = 0; i < n; i++) {
    total[belong[i]]++;
  }
  vector<vector<ll>> ng(cnt);
  for (auto& [u, v] : edges) {
    if (belong[u] != belong[v]) {
      ng[belong[v]].push_back(belong[u]);
    }
  }
  ll res = 0;
  vector<ll> q, nq, seen(cnt);
  for (int i = 0; i < cnt; i++) {
    if (total[i] > 1) q.push_back(i), res += total[i], seen[i] = 1;
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      for (auto& ne : ng[node]) {
        if (seen[ne] == 0) {
          seen[ne] = 1;
          nq.push_back(ne);
          res++;
        }
      }
    }
  }
  cout << res << "\n";
}
