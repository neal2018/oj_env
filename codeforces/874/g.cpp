#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<set<array<int, 2>>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].insert({v, i}), g[v].insert({u, i});
    }
    vector<int> res;
    if ([&] {
          if (n % 3 != 0) return false;
          // neg number of needle, deg, id;
          vector<int> needle_cnt(n);
          for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) needle_cnt[(*g[i].begin())[0]]++;
          }
          set<array<int, 3>> process;
          for (int i = 0; i < n; i++) {
            if (g[i].size() != 1) {
              process.insert({-needle_cnt[i], int(g[i].size()), i});
            }
          }
          auto add_needle_cnt = [&](int node) {
            process.erase({-needle_cnt[node], int(g[node].size()), node});
            needle_cnt[node]++;
            process.insert({-needle_cnt[node], int(g[node].size()), node});
          };
          auto cut = [&](int e_id, int to, int from) {
            res.push_back(e_id);
            process.erase({-needle_cnt[to], int(g[to].size()), to});
            g[to].erase({from, e_id});
            if (g[to].size() != 1) {
              process.insert({-needle_cnt[to], int(g[to].size()), to});
            } else {
              for (auto& [nne, _] : g[to]) add_needle_cnt(nne);
            }
          };

          while (process.size()) {
            auto [neg_cnt, cur_deg, id] = *process.begin();
            process.erase(process.begin());
            auto cnt = -neg_cnt;
            if (cnt > 2) return false;
            if (cnt == 2) {
              for (auto it = g[id].begin(); it != g[id].end();) {
                auto [ne, e_id] = *it;
                if (g[ne].size() == 1) {
                  it++;
                  continue;
                }
                cut(e_id, ne, id);
                it = g[id].erase(it);
              }
            } else if (cnt == 1) {
              if (g[id].size() != 2) return false;
              for (auto [ne, e_id] : g[id]) {
                if (g[ne].size() == 1) continue;
                for (auto nit = g[ne].begin(); nit != g[ne].end();) {
                  auto [nne, ne_id] = *nit;
                  if (nne == id) {
                    nit++;
                    continue;
                  }
                  cut(ne_id, nne, ne);
                  nit = g[ne].erase(nit);
                }
              }
            }
          }
          return true;
        }()) {
      cout << res.size() << "\n";
      for (auto& x : res) cout << x + 1 << " ";
      cout << "\n";
    } else {
      cout << "-1\n";
    }
  }
}
