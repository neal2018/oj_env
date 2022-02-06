#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<array<int, 2>> a(n), b(n);
  vector<int> deg_a(n), deg_b(n);
  for (auto& [x, y] : a) {
    cin >> x >> y, x--, y--;
    if (x != -1) deg_a[x]++;
    if (y != -1) deg_a[y]++;
  }
  for (auto& [x, y] : b) {
    cin >> x >> y, x--, y--;
    if (x != -1) deg_b[x]++;
    if (y != -1) deg_b[y]++;
  }
  int ra = 0, rb = 0;
  for (int i = 0; i < n; i++)
    if (deg_a[i] == 0) ra = i;
  for (int i = 0; i < n; i++)
    if (deg_b[i] == 0) rb = i;

  vector<int> res;
  function<void(int, int)> solve = [&](int cur_root, int cur_b) {
    if (cur_root == -1) return;
    vector<int> path = {-1};
    function<bool(int)> dfs = [&](int cur) {
      if (cur == -1) return false;
      if (cur == cur_root) return true;
      path.push_back(cur);
      bool ans = dfs(b[cur][0]) || dfs(b[cur][1]);
      if (!ans) path.pop_back();
      return ans;
    };
    dfs(cur_b);
    ll sz = path.size();
    reverse(path.begin(), path.end());
    auto zig = [&](int node, int fa, int fa_fa) {
      if (fa_fa != -1) {
        if (b[fa_fa][0] == fa) {
          b[fa_fa][0] = node;
        } else {
          b[fa_fa][1] = node;
        }
      }
      if (b[fa][0] == node) {
        b[fa][0] = b[node][1];
        b[node][1] = fa;
      } else {
        b[fa][1] = b[node][0];
        b[node][0] = fa;
      }
    };
    for (int i = 0; i < sz - 1; i++) {
      zig(cur_root, path[i], path[i + 1]);
      res.push_back(cur_root);
    }
    solve(a[cur_root][0], b[cur_root][0]);
    solve(a[cur_root][1], b[cur_root][1]);
  };
  solve(ra, rb);
  cout << res.size() << "\n";
  for (auto& x : res) cout << x + 1 << "\n";
}