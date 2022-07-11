#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges(m);
    vector<vector<int>> g(n);
    for (auto& [u, v] : edges) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v);
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
    for (int i = 0; i < n; i++) {
      if (belong[i] == -1) tarjan(i);
    }
    vector<int> sz(cnt), deg(cnt);
    vector<set<int>> total(cnt);
    for (int i = 0; i < cnt; i++) total[i].insert(i);
    for (int i = 0; i < n; i++) {
      sz[belong[i]]++;
    }
    vector<vector<int>> ng(cnt);
    for (auto& [u, v] : edges) {
      if (belong[u] != belong[v]) {
        ng[belong[u]].push_back(belong[v]);
        deg[belong[v]]++;
      }
    }
    vector<int> q, nq;
    for (int i = 0; i < cnt; i++) {
      if (deg[i] == 0) {
        q.push_back(i);
      }
    }
    ll res = 0;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        ll sum = 0;
        for (auto& x : total[node]) {
          if (x == -1) {
            sum = k + 1;
            break;
          }
          sum += sz[x];
        }
        if (sum > k) res += sz[node];
        for (auto& ne : ng[node]) {
          {
            if (total[ne] == set{-1} || total[node] == set{-1}) {
              total[ne] = set{-1};
            }
            for (auto& x : total[node]) {
              total[ne].insert(x);
            }
            if (total[ne].size() > k) total[ne] = set{-1};
          }
          if (--deg[ne] == 0) {
            nq.push_back(ne);
          }
        }
      }
    }
    cout << res << "\n";
  }
}
