#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    set<pair<int, int>> ast, bst;  // -pow, i
    for (int i = 0; i < n; i++) {
      ast.insert({-a[i], i}), bst.insert({-b[i], i});
    }
    auto dfs = [&](auto self, int i, int f) {
      auto& bb = f ? ast : bst;
      auto& bbb = f ? a : b;
      if (bb.count({-bbb[i], i}) == 0) return;
      vector<int> toremove;
      while (bb.begin()->second != i) {
        toremove.push_back(bb.begin()->second);
        bb.erase(bb.begin());
      }
      bb.erase(bb.begin());
      for (auto& x : toremove) self(self, x, !f);
    };
    int root = ast.begin()->second;
    ast.erase(ast.begin());
    dfs(dfs, root, 0);
    vector<int> res(n, 1);
    for (auto& [x, y] : ast) res[y] = 0;
    for (auto& x : res) cout << x;
    cout << '\n';
  }
}