#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ull add = rng();

ull h(ull x) { return x * x * x * 1237123 + 19260819; }
ull f(ull x) {
  ull cur = h(x & ((1ull << 31) - 1)) + h(x >> 31) + add;
  return cur;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0, u, v; i < n - 1; i++) {
      cin >> u >> v, u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    function<array<ull, 2>(int, int)> dfs = [&](int node, int fa) -> array<ull, 2> {
      ull cur = 1;
      set<array<ull, 2>> st;
      for (auto& ne : g[node]) {
        if (ne == fa) continue;
        auto [hash, good] = dfs(ne, node);
        cur += f(h(hash));
        if (st.count({hash, good})) {
          st.erase({hash, good});
        } else {
          st.insert({hash, good});
        }
      }
      if (st.size() == 0 || (st.size() == 1 && (*st.begin())[1] == 1)) {
        return {cur, 1};
      } else {
        return {cur, 0};
      }
    };
    auto [hash, good] = dfs(0, -1);
    cout << (good ? "YES\n" : "NO\n");
  }
}
