#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 inf = 1e18;

struct UnionFind {
  std::vector<int> p;
  UnionFind(int n) : p(n) { std::iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; i++) {
    std::cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--;
  }

  std::vector<int> res(n);
  constexpr int BIT = 30;
  for (int bit = BIT; bit >= 0; bit--) {
    auto uf = UnionFind(2 * n);
    for (int i = 0; i < m; i++) {
      bool is_diff = (c[i] >> bit) & 1;
      if (!is_diff) {
        uf.merge(a[i], b[i]);
        uf.merge(a[i] + n, b[i] + n);
      } else {
        uf.merge(a[i], b[i] + n);
        uf.merge(a[i] + n, b[i]);
      }
    }
    std::vector<std::vector<int>> group(2 * n);
    std::vector<int> seen(2 * n);
    for (int i = 0; i < n; i++) {
      if (uf.find(i) == uf.find(i + n)) {
        std::cout << "-1\n";
        return 0;
      }
      group[uf.find(i)].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      auto ri = uf.find(i);
      auto ori = uf.find(i + n);
      if (seen[ri] || seen[ori]) {
        continue;
      }

      auto need = group[ri];
      if (group[ri].size() > group[ori].size()) {
        need = group[ori];
      }
      for (auto x : need) {
        res[x % n] += 1 << bit;
      }
      seen[ri] = 1, seen[ori] = 1;
    }
  }
  for (auto x : res) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}
