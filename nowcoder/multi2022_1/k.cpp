#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<pair<int, int>> pruefer_decode(vector<int> const& code) {
  int n = int(code.size()) + 2;
  vector<int> degree(n, 1);
  for (int i : code) degree[i]++;

  int ptr = 0;
  while (degree[ptr] != 1) ptr++;
  int leaf = ptr;

  vector<pair<int, int>> edges;
  for (int v : code) {
    edges.emplace_back(leaf, v);
    if (--degree[v] == 1 && v < ptr) {
      leaf = v;
    } else {
      ptr++;
      while (degree[ptr] != 1) ptr++;
      leaf = ptr;
    }
  }
  edges.emplace_back(leaf, n - 1);
  return edges;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout<< fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<ll, 3>> a(n);
    for (auto& [x, y, r] : a) cin >> x >> y >> r;
    vector<int> prufer;
    ld res = 1e18;
    auto dist = [&](int i, int j) {
      return ld(sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) +
                     (a[i][1] - a[j][1]) * (a[i][1] - a[j][1])));
    };
    auto check = [&]() {
      auto&& edges = pruefer_decode(prufer);
      ld cur = 0;
      for (auto& [i, j] : edges) {
        cur += dist(i, j) - a[i][2] - a[j][2];
      }
      res = min(res, cur);
    };
    function<void(int)> dfs = [&](int cur) {
      if (cur == n - 2) {
        check();
        return;
      }
      for (int i = 0; i < n; i++) {
        prufer.push_back(i);
        dfs(cur + 1);
        prufer.pop_back();
      }
    };
    dfs(0);
    cout << res << "\n";
  }
}
