#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m[2], u, v;
  cin >> n >> m[0] >> m[1];
  vector<vector<int>> uf(2, vector<int>(n));
  vector<int> x, y;

  function<int(int, int)> find = [&](int x, int id) {
    return x == uf[id][x] ? x : (uf[id][x] = find(uf[id][x], id));
  };
  auto merge = [&](int x, int y, int id) {
    auto px = find(x, id), py = find(y, id);
    if (px != py) {
      uf[id][px] = py;
    }
  };
  auto check = [&](int x, int y, int id) { return find(x, id) == find(y, id); };
  auto merge2 = [&](int x, int y) {
    merge(x, y, 0), merge(x, y, 1);
    cout << x + 1 << " " << y + 1 << endl;
  };
  for (int id = 0; id < 2; id++) {
    iota(uf[id].begin(), uf[id].end(), 0);
    for (int j = 0; j < m[id]; j++) {
      cin >> u >> v;
      u--, v--;
      merge(u, v, id);
    }
  }
  cout << n - 1 - max(m[0], m[1]) << endl;
  for (int i = 1; i < n; i++) {
    auto a = check(0, i, 0), b = check(0, i, 1);
    if (!a && !b) {
      merge2(0, i);
    } else if (!a) {
      if (y.size() > 0) {
        merge2(i, y.back());
        y.pop_back();
      } else {
        x.push_back(i);
      }
    } else if (!b) {
      if (x.size() > 0) {
        merge2(i, x.back());
        x.pop_back();
      } else {
        y.push_back(i);
      }
    }
    while (x.size() > 0 && check(0, x.back(), 0)) x.pop_back();
    while (y.size() > 0 && check(0, y.back(), 1)) y.pop_back();
  }
}