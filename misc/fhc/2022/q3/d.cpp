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
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> q(m);
    for (auto& [x, y] : q) cin >> x >> y, x--, y--;
    auto check = [&](int mid) {
      vector<int> represent(n);
      int cnt = n;
      iota(represent.begin(), represent.end(), 0);
      UnionFind uf(n);
      for (int i = 0; i < mid; i++) {
        auto [from, to] = q[i];
        if (uf.find(represent[from]) != represent[from]) {
          continue;
        }
        if (uf.find(represent[to]) != represent[to]) {
          uf.p.push_back(cnt);
          represent[to] = cnt++;
        }
        uf.merge(represent[from], represent[to]);
      }
      for (int i = 0; i < n; i++) {
        if (i % k != 0 && uf.find(i) != uf.find(i - 1)) {
          return false;
        }
      }
      return true;
    };
    if (!check(m)) {
      cout << "-1\n";
      continue;
    }
    int l = 0, r = m;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << "\n";
  }
}
