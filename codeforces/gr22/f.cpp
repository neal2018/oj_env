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
    auto ask = [&](int x) {
      cout << "? " << x + 1 << endl;
      int res;
      cin >> res;
      return res - 1;
    };
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; auto& [x, id] : a) cin >> x, id = i++;
    sort(a.begin(), a.end(), greater());
    UnionFind uf(n);
    vector<int> seen(n);
    for (auto [d, id] : a) {
      if (seen[id]) continue;
      for (int i = 0; i < d; i++) {
        auto res = ask(id);
        uf.merge(res, id);
        if (seen[res]) break;
        seen[res] = 1;
      }
      seen[id] = 1;
    }
    vector<int> color(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      mp[uf.find(i)].push_back(i);
    }
    int id = 0;
    for (auto& [k, v] : mp) {
      for (auto& x : v) color[x] = id;
      id++;
    }
    cout << "! ";
    for (auto& x : color) cout << x + 1 << " ";
    cout << endl;
  }
}
