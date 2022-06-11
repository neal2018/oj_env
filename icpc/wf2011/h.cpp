#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  for (int case_num = 0, m; cin >> m, m; case_num++) {
    cout << "Case " << case_num + 1 << ": ";
    ll n = -1;
    vector<pair<ll, ll>> edges(m);
    for (auto& [x, y] : edges) {
      cin >> x >> y, x--, y--;
      n = max({n, x, y});
    }
    n++;
    vector<vector<ll>> g(n);
    for (auto& [x, y] : edges) {
      g[x].push_back(y), g[y].push_back(x);
    }
    int cnt = 0, now = 0;
    vector<vector<ll>> e1(n);
    vector<ll> dfn(n, -1), low(n), stk;
    function<void(ll)> tarjan = [&](ll node) {
      dfn[node] = low[node] = now++, stk.push_back(node);
      for (auto& ne : g[node]) {
        if (dfn[ne] == -1) {
          tarjan(ne);
          low[node] = min(low[node], low[ne]);
          if (low[ne] == dfn[node]) {
            e1.push_back({});
            while (true) {
              auto x = stk.back();
              stk.pop_back();
              e1[n + cnt].push_back(x);
              e1[x].push_back(n + cnt);
              if (x == ne) break;
            }
            e1[node].push_back(n + cnt);
            e1[n + cnt].push_back(node);
            cnt++;
          }
        } else {
          low[node] = min(low[node], dfn[ne]);
        }
      }
    };
    tarjan(0);
    if (cnt == 1) {
      cout << 2 << " " << n * (n - 1) / 2 << "\n";
    } else {
      vector<ll> q, deg(cnt + n);
      for (int i = 0; i < cnt + n; i++) {
        deg[i] = e1[i].size();
        if (deg[i] == 1) q.push_back(i);
      }
      vector<ll> leaf;
      for (auto& node : q) {
        for (auto& ne : e1[node]) {
          deg[ne]--;
          if (deg[ne] == 1) {
            leaf.push_back(ne);
          }
        }
      }
      ll res = leaf.size(), total = 1;
      for (auto& node : leaf) {
        total *= ((ll)e1[node].size() - 1);
      }
      cout << res << " " << total << "\n";
    }
  }
}
