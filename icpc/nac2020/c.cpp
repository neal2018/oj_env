#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  int n, q;
  cin >> n >> q;
  vector<array<ll, 4>> circles(n + q);
  vector<array<ll, 3>> ops;  // x, y, is_end
  ops.reserve((n + q) * 2);
  for (int i = 0; i < n + q; i++) {
    auto& [x, y, r, id] = circles[i];
    cin >> x >> y >> r, id = (i >= n ? (i - n) : -1);
    ops.push_back({x - r, i, 0});
    ops.push_back({x + r, i, 1});
  }
  sort(ops.begin(), ops.end());
  ll X = 0;
  auto cal = [&](const array<ll, 2>& a) {
    auto [is_down, i] = a;
    auto& [x, y, r, id] = circles[i];
    ll dy2 = r * r - (x - X) * (x - X);
    return double(y) + (1.0 - 2 * double(is_down)) * sqrt(dy2);
  };
  auto cmp = [&](const array<ll, 2>& a, const array<ll, 2>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return cal(a) > cal(b);
  };
  set<array<ll, 2>, decltype(cmp)> st(cmp);
  vector<ll> parent(n + q, -1);
  for (auto& [x, i, is_end] : ops) {
    X = x;
    if (is_end) {
      st.erase({0, i});
      st.erase({1, i});
    } else {
      auto it = st.lower_bound({1, i});
      if (it != st.begin()) {
        it--;
        auto [p_is_down, p_i] = *it;
        if (p_is_down) {
          parent[i] = parent[p_i];
        } else {
          parent[i] = p_i;
        }
      }
      st.insert({0, i});
      st.insert({1, i});
    }
  }
  vector<ll> dp(n + q), dp_not(n + q);
  vector<ll> res(q);
  vector<vector<int>> g(n + q);
  for (int i = 0; i < n + q; i++) {
    if (parent[i] != -1) {
      g[parent[i]].push_back(i);
    }
  }
  function<void(int, int)> dfs = [&](int node, int fa) {
    for (auto& ne : g[node]) {
      if (ne != fa) {
        dfs(ne, node);
        dp_not[node] += max(dp[ne], dp_not[ne]);
        dp[node] += dp_not[ne];
      }
    }
    auto id = circles[node][3];
    dp[node] += 1;
    if (id != -1) {
      res[id] = max(dp[node], dp_not[node]);
      dp[node]--;
      swap(dp[node], dp_not[node]);
    }
  };
  for (int i = 0; i < n + q; i++) {
    if (parent[i] == -1) dfs(i, -1);
  }
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
