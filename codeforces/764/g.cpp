#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> a(m);
    for (auto& [x, y, z] : a) cin >> x >> y >> z, x--, y--;
    int cur = 0;
    for (int high = 30; high >= 0; high--) {
      vector<int> p(n, -1);
      function<int(int)> find = [&](int x) { return (p[x] < 0) ? x : (p[x] = find(p[x])); };
      auto merge = [&](int x, int y) { p[find(x)] = find(y); };
      int cur_try = cur * 2;
      for (auto& [x, y, w] : a) {
        if ((cur_try | (w >> high)) == cur_try) merge(x, y);
      }
      vector<int> res;
      for (int i = 0; i < n; i++) res.push_back(find(i));
      sort(res.begin(), res.end());
      res.erase(unique(res.begin(), res.end()), res.end());
      if (res.size() == 1) {
        cur *= 2;
      } else {
        cur = cur * 2 + 1;
      }
    }
    cout << cur << "\n";
  }
}