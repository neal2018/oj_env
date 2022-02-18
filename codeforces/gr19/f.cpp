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
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  int root = int(max_element(a.begin(), a.end()) - a.begin());
  vector<ll> maxi(n);
  function<ll(int, int)> get_maxi = [&](int node, int fa) {
    maxi[node] = a[node];
    for (auto& ne : g[node]) {
      if (ne != fa) maxi[node] = max(maxi[node], get_maxi(ne, node));
    }
    return maxi[node];
  };
  get_maxi(root, -1);
  ll res = 0;
  function<void(int, int, ll)> solve = [&](int node, int fa, ll up) {
    int pos = -1;
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      if (pos == -1 || maxi[ne] > maxi[pos]) pos = ne;
    }
    if (pos == -1) {
      res += up;
    } else {
      for (auto& ne : g[node]) {
        if (ne == fa) {
          continue;
        } else if (ne == pos) {
          solve(ne, node, up);
        } else {
          solve(ne, node, maxi[ne]);
        }
      }
    }
  };
  int pos = -1, pos2 = -1;
  for (auto& ne : g[root]) {
    if (pos == -1 || maxi[ne] > maxi[pos]) {
      pos2 = pos, pos = ne;
    } else if (pos2 == -1 || maxi[ne] > maxi[pos2]) {
      pos2 = ne;
    }
  }
  if (pos2 == -1) res += maxi[root];
  for (auto& ne : g[root]) {
    if (ne == pos || ne == pos2) {
      solve(ne, root, maxi[root]);
    } else {
      solve(ne, root, maxi[ne]);
    }
  }
  cout << res << "\n";
}
