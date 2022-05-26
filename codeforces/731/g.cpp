#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    vector<int> marked(n);
    for (auto& [u, v] : edges) {
      cin >> u >> v, u--, v--;
      if (u == v) {
        marked[u] = 1;
      } else {
        g[u].push_back(v);
      }
    }

    int cnt = 0, now = 0;
    vector<int> dfn(n, -1), low(n), belong(n, -1), stk;
    function<void(int)> tarjan = [&](int node) {
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
    tarjan(0);
    vector<vector<int>> ng(cnt);
    vector<int> deg(n);
    for (auto& [u, v] : edges) {
      if (dfn[u] != -1 && dfn[v] != -1 && belong[u] != belong[v]) {
        ng[belong[u]].push_back(belong[v]), deg[belong[v]]++;
      }
    }
    vector<int> color(cnt, -1), red(cnt), black(cnt);

    {
      vector<int> q, nq, seen(cnt);
      for (int i = 0; i < cnt; i++) {
        if (deg[i] > 1) {
          q.push_back(i);
          seen[i] = 1;
          red[i] = 1;
        }
      }
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          for (auto& ne : ng[node]) {
            if (seen[ne] == 0) {
              nq.push_back(ne);
              seen[ne] = 1, red[ne] = 1;
            }
          }
        }
      }
    }
    vector<int> sz(cnt);
    for (int i = 0; i < n; i++) {
      if (dfn[i] == -1) continue;
      sz[belong[i]]++;
      if (marked[i]) black[belong[i]] = 1;
    }
    for (int i = 0; i < cnt; i++) {
      if (sz[i] > 1) black[i] = 1;
    }
    {
      vector<int> q, nq, seen(cnt);
      for (int i = 0; i < cnt; i++) {
        if (black[i]) {
          q.push_back(i);
          seen[i] = 1;
        }
      }
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          for (auto& ne : ng[node]) {
            if (seen[ne] == 0) {
              nq.push_back(ne);
              seen[ne] = 1, black[ne] = 1;
            }
          }
        }
      }
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      if (dfn[i] != -1) {
        res[i] = 1;
        if (red[belong[i]]) res[i] = 2;
        if (black[belong[i]]) res[i] = -1;
      }
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
