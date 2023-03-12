#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

struct RerootDp {
  RerootDp(auto add, auto del, auto calc, const auto& g) {
    function<void(int, int)> prepare = [&](int node, int fa) {
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        prepare(ne, node);
        add(node, ne);
      }
    };
    prepare(0, -1);

    function<void(int, int)> dfs = [&](int node, int fa) {
      if (fa != -1) add(node, fa);
      calc(node);
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        del(node, ne);
        dfs(ne, node);
        add(node, ne);
      }
      if (fa != -1) del(node, fa);
    };
    dfs(0, -1);
  };
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[u]++, deg[v]++;
    }
    if (*max_element(deg.begin(), deg.end()) == 2) {
      cout << n << "\n";
      continue;
    }

    vector<multiset<int>> direct(n), indirect(n);
    vector<int> linked(n, 1);
    auto add = [&](int node, int ne) {
      direct[node].insert(linked[ne]);
      linked[node] = (*direct[node].begin()) + 1;
      int extra = inf;
      if (indirect[ne].size()) extra = min(extra, *indirect[ne].begin());
      if (direct[ne].size() > 1) extra = min(extra, *next(direct[ne].begin()));
      if (extra != inf) indirect[node].insert(extra);
    };

    auto del = [&](int node, int ne) {
      direct[node].extract(linked[ne]);
      linked[node] = (direct[node].size() ? (*direct[node].begin()) : 0) + 1;
      int extra = inf;
      if (indirect[ne].size()) extra = min(extra, *indirect[ne].begin());
      if (direct[ne].size() > 1) extra = min(extra, *next(direct[ne].begin()));
      if (extra != inf) indirect[node].extract(extra);
    };

    int res = 0;
    auto calc = [&](int node) {
      int cur = (indirect[node].size() ? *indirect[node].begin() : inf);
      assert(direct[node].size() > 0);
      assert(linked[node] > 1);
      auto second = (direct[node].size() > 1 ? *(next(direct[node].begin())) : inf);
      cur = min({cur, linked[node], second});
      res = max(res, cur);
    };

    RerootDp(add, del, calc, g);

    cout << res << "\n";
  }
}
