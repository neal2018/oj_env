#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct UnionFind {
  std::vector<int> p;
  UnionFind(int n) : p(n) { std::iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  int a_max = 0;
  std::cin >> n >> m;
  std::vector a(n, std::vector<int>(m));
  for (auto& r : a) {
    for (auto& x : r) std::cin >> x, a_max = std::max(a_max, x);
  }
  int q;
  std::cin >> q;
  std::vector<std::array<int, 6>> queries(q);
  for (auto& [a, b, y, c, d, z] : queries) {
    std::cin >> a >> b >> y >> c >> d >> z, a--, b--, c--, d--;
  }

  auto tag = [&](int x, int y) { return x * m + y; };

  std::vector<std::array<int, 3>> edges;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i < n - 1) edges.push_back({std::min(a[i][j], a[i + 1][j]), tag(i, j), tag(i + 1, j)});
      if (j < m - 1) edges.push_back({std::min(a[i][j], a[i][j + 1]), tag(i, j), tag(i, j + 1)});
    }
  }
  std::sort(edges.begin(), edges.end());
  std::reverse(edges.begin(), edges.end());

  int mini = a_max;
  for (auto& [w, x, y] : edges) {
    mini = std::min(mini, w);
  }

  std::vector<std::array<int, 2>> res(q, {mini, a_max});

  while ([&] {
    for (auto [l, r] : res) {
      if (l < r) {
        return true;
      }
    }
    return false;
  }()) {
    std::vector<vector<int>> checks(a_max + 1);
    for (int i = 0; auto& [l, r] : res) {
      auto mid = (l + r + 1) / 2;
      checks[mid].push_back(i);
      i++;
    }

    auto uf = UnionFind(n * m);
    int check_id = int(checks.size()) - 1;
    for (int i = 0, j = 0; i < edges.size(); i = j) {
      auto w = edges[i][0];
      for (; check_id > w; check_id--) {
        for (auto qi : checks[check_id]) {
          auto [a, b, y, c, d, z] = queries[qi];
          if (uf.find(tag(a, b)) == uf.find(tag(c, d))) {
            res[qi][0] = check_id;
          } else {
            res[qi][1] = check_id - 1;
          }
        }
      }
      for (j = i; j < edges.size() && edges[i][0] == edges[j][0]; j++) {
        auto [_, x, y] = edges[j];
        uf.merge(x, y);
      }
    }
    for (; check_id >= 0; check_id--) {
      for (auto qi : checks[check_id]) {
        auto [a, b, y, c, d, z] = queries[qi];
        if (uf.find(tag(a, b)) == uf.find(tag(c, d))) {
          res[qi][0] = check_id;
        } else {
          res[qi][1] = check_id - 1;
        }
      }
    }
  }

  for (int i = 0; i < q; i++) {
    auto need = res[i][0];
    auto [a, b, y, c, d, z] = queries[i];
    if (y <= need) {
      std::cout << std::abs(z - y) << "\n";
    } else {
      std::cout << std::abs(y - need) + std::abs(z - need) << "\n";
    }
  }
}
