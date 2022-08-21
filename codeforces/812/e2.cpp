#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) { p[find(x)] = find(y); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    auto uf = UnionFind(2 * n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i][j] > a[j][i]) {
          if (uf.find(i) != uf.find(j)) {
            uf.merge(i, j + n), uf.merge(j, i + n);
            swap(a[i][j], a[j][i]);
          }
        } else if (a[i][j] < a[j][i]) {
          if (uf.find(i) != uf.find(j + n)) {
            uf.merge(i, j), uf.merge(i + n, j + n);
          } else {
            swap(a[i][j], a[j][i]);
          }
        }
      }
    }
    for (auto& r : a) {
      for (auto& x : r) cout << x << " ";
      cout << "\n";
    }
  }
}
