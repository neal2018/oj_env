#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  int root = int(max_element(a.begin(), a.end()) - a.begin());
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<ll> maxi(n);
  function<void(int, int)> get_maxi = [&](int node, int fa) {
    maxi[node] = a[node];
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      get_maxi(ne, node);
      maxi[node] = max(maxi[node], maxi[ne]);
    }
  };
  get_maxi(root, -1);
  ll res = 0;
  function<void(int, int)> solve_solo;
  function<void(int, int, ll)> solve_max = [&](int node, int fa, ll up) {
    int pos = -1;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      if (pos == -1 || maxi[ne] > maxi[pos]) {
        pos = ne;
      }
    }
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      if (pos == ne) {
        solve_max(ne, node, up);
      } else {
        solve_solo(ne, node);
      }
    }
    if (pos == -1) {
      res += up;
    }
  };
  solve_solo = [&](int node, int fa) {
    int pos1 = -1, pos2 = -1;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      if (pos1 == -1 || maxi[ne] > maxi[pos1]) {
        pos1 = ne;
      } else if (pos2 == -1 || maxi[ne] > maxi[pos2]) {
        pos2 = ne;
      }
    }
    if (pos1 != -1) {
      solve_max(pos1, node, max(maxi[node], maxi[pos1]));
    } else {
      res += maxi[root];
      return;
    }
    if (pos2 != -1) {
      solve_max(pos2, node, max(maxi[node], maxi[pos2]));
    } else {
      res += maxi[root];
    }
    for (auto& ne : g[node]) {
      if (ne == pos1 || ne == pos2 || ne == fa) {
        continue;
      } else {
        solve_solo(ne, node);
      }
    }
  };
  int pos1 = -1, pos2 = -1;
  for (auto& ne : g[root]) {
    if (pos1 == -1 || maxi[ne] > maxi[pos1]) {
      pos1 = ne;
    } else if (pos2 == -1 || maxi[ne] > maxi[pos2]) {
      pos2 = ne;
    }
  }
  if (pos1 != -1) {
    solve_max(pos1, root, maxi[root]);
  } else {
    res += maxi[root];
  }
  if (pos2 != -1) {
    solve_max(pos2, root, maxi[root]);
  } else {
    res += maxi[root];
  }
  for (auto& ne : g[root]) {
    if (ne == pos1 || ne == pos2) {
      continue;
    } else {
      solve_solo(ne, root);
    }
  }
  cout << res << "\n";
}
