#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(2 * n);
  for (int x, y; auto i : views::iota(0, n)) {
    cin >> x >> y, x--, y--;
    g[x].push_back({y, i}), g[y].push_back({x, i});
  }
  vector<string> res_s(2), res_t(2);
  vector<vector<int>> res(2);
  vector<int> seen(2 * n), seen_e(n);
  for (auto i : views::iota(0, 2 * n)) {
    if (seen[i]) continue;
    vector<int> pass;
    function<void(int)> dfs = [&](int node) {
      pass.push_back(node);
      if (seen[node]) return;
      seen[node] = 1;
      for (auto& [ne, id] : g[node]) {
        if (seen_e[id]) continue;
        seen_e[id] = 1, dfs(ne);
        pass.push_back(node);
      }
    };
    dfs(i);
    if (pass.size() == 1) continue;
    if (pass.size() == 3) {
      cout << "-1\n";
      return 0;
    }
    pass.pop_back();
    int k = int(pass.size() / 2);
    for (auto j : views::iota(0, k)) res[0].push_back(pass[j]);
    for (auto j : views::iota(0, k)) res[1].push_back(pass[2 * k - 1 - j]);
    if (k & 1) {
      res_t[0] += "U", res_t[1] += "D";
      for ([[maybe_unused]] auto j : views::iota(0, k / 2)) {
        res_s[0] += "LR", res_s[1] += "LR";
        res_t[0] += "LR", res_t[1] += "LR";
      }
      res_s[0] += "U", res_s[1] += "D";
    } else {
      for ([[maybe_unused]] auto j : views::iota(0, k / 2)) {
        res_s[0] += "LR", res_s[1] += "LR";
      }
      res_t[0] += "U", res_t[1] += "D";
      for ([[maybe_unused]] auto j : views::iota(0, k / 2 - 1)) {
        res_t[0] += "LR", res_t[1] += "LR";
      }
      res_t[0] += "U", res_t[1] += "D";
    }
  }
  cout << 2 << " " << n << "\n\n";
  for (auto& r : res) {
    for (auto& x : r) cout << x + 1 << " ";
    cout << "\n";
  }
  cout << "\n";
  for (auto& s : res_s) cout << s << "\n";
  cout << "\n";
  for (auto& t : res_t) cout << t << "\n";
}
