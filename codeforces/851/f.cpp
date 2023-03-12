#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}
  int find(int x) { return p[x] < 0 ? x : (p[x] = find(p[x])); }
  void merge(int x, int y) {
    int r_x = find(x), r_y = find(y);
    if (r_x == r_y) return;
    int sz_x = -p[r_x], sz_y = -p[r_y];
    if (sz_x < sz_y) swap(r_x, r_y), swap(x, y), swap(sz_x, sz_y);
    p[r_x] = -(sz_x + sz_y), p[r_y] = r_x;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<array<int, 2>> edges(n - 1);
  vector<int> freq(n);
  for (auto& [x, y] : edges) cin >> x >> y, x--, y--, freq[x] ^= 1, freq[y] ^= 1;
  vector<array<int, 3>> conditions(q);
  for (auto& [x, y, t] : conditions) cin >> x >> y >> t, x--, y--;
  vector<int> res(n);
  if ([&] {
        for (int bit = 29; bit >= 0; bit--) {
          UnionFind uf(2 * n);
          for (auto [x, y, t] : conditions) {
            if ((t >> bit) & 1) {
              uf.merge(x, y + n);
              uf.merge(y, x + n);
            } else {
              uf.merge(x, y);
              uf.merge(x + n, y + n);
            }
          }
          for (int i = 0; i < n; i++) {
            if (uf.find(i) == uf.find(i + n)) return false;
          }
          vector<array<vector<int>, 2>> parts;
          vector<vector<int>> group(2 * n);
          for (int i = 0; i < n; i++) group[uf.find(i)].push_back(i);
          vector<int> seen(2 * n);
          for (int i = 0; i < n; i++) {
            if (seen[uf.find(i)] || seen[uf.find(i + n)]) continue;
            parts.push_back({group[uf.find(i)], group[uf.find(i + n)]});
            seen[uf.find(i)] = 1, seen[uf.find(i + n)] = 1;
          }
          int cur = 0;
          for (auto& [v1, v2] : parts) {
            for (auto& x : v2) cur ^= freq[x];
          }
          if (cur == 1) {
            for (auto& [v1, v2] : parts) {
              for (auto& x : v1) cur ^= freq[x];
              for (auto& x : v2) cur ^= freq[x];
              if (cur == 0) {
                swap(v1, v2);
                break;
              }
            }
          }
          for (auto& [v1, v2] : parts) {
            for (auto& x : v2) res[x] |= (1 << bit);
          }
        }
        return true;
      }()) {
    cout << "Yes\n";
    for (auto& [x, y] : edges) cout << (res[x] ^ res[y]) << " ";
    cout << "\n";
  } else {
    cout << "No\n";
  }
}
