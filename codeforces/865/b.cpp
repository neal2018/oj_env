#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto clear = [&] {
    int got = 0;
    cin >> got;
    if (got != 1) exit(0);
  };

  auto ask = [&](int i, int j) {
    if (i == j) return 0;
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    if (res == -2) exit(0);
    return res;
  };

  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    auto add = [&](int x) {
      if (x < 2 || x > 2 * n) return;
      cout << "+ " << x << endl;
      clear();
      x -= 2;
      for (int i = 0; i < n; i++) {
        if (0 <= x - i && x - i < n && i < x - i) {
          g[i].push_back(x - i);
          g[x - i].push_back(i);
        }
      }
    };
    if (n % 2 == 1) {
      add(n);
      add(n + 2);
    } else {
      add(n - 1);
      add(n + 1);
    }
    vector<array<int, 2>> dist(n);
    for (int i = 1; i < n; i++) {
      int x = ask(0, i);
      dist[i] = {x, i};
    }
    sort(dist.rbegin(), dist.rend());
    int root = dist[0][1];
    dist = vector<array<int, 2>>(n);
    for (int i = 0; i < n; i++) {
      if (i == root) {
        dist[i] = {0, root};
      } else {
        int x = ask(root, i);
        dist[i] = {x, i};
      }
    }
    sort(dist.begin(), dist.end());
    vector<int> path;
    auto tree_root = [&] {
      for (int i = 0; i < n; i++) {
        if (g[i].size() == 1) return i;
      }
      return -1;
    }();
    int cur = tree_root, prev = -1;
    while (true) {
      path.push_back(cur);
      int n_cur = g[cur][0] == prev ? g[cur][1] : g[cur][0];
      prev = cur, cur = n_cur;
      if (g[cur].size() == 1) {
        path.push_back(cur);
        break;
      }
    }
    cout << "! ";
    {
      vector<int> res(n);
      for (int i = 0; i < n; i++) {
        res[dist[i][1]] = path[i];
      }
      for (auto& x : res) cout << x + 1 << " ";
      reverse(path.begin(), path.end());
      for (int i = 0; i < n; i++) {
        res[dist[i][1]] = path[i];
      }
      for (auto& x : res) cout << x + 1 << " ";
    }
    cout << endl;
    clear();
  }
}
