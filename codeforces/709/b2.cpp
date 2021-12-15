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
    map<int, int> a;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      a[i] = x;
    }
    set<pair<int, int>> good;
    int pre = -1;
    for (int i = 0; i < n; i++) {
      if (pre == -1) {
        pre = a[i];
        continue;
      }
      if (gcd(a[i], pre) == 1) {
        good.insert({i - 1, i});
        pre = -1;
      } else {
        pre = a[i];
      }
    }
    if (pre != -1 && gcd(pre, a[0]) == 1) good.insert({n - 1, 0});
    vector<int> res;
    while (good.size() && a.size() > 1) {
      vector<pair<int, int>> toi;
      set<int> removed;
      for (auto it = good.begin(); it != good.end();) {
        int val = it->second;
        if (val == n) val = 0;
        res.push_back(val);
        removed.insert(val);
        auto a_it = a.find(val);
        auto a_nex = (a_it == --a.end() ? a.begin() : next(a_it));
        auto a_pre = (a_it == a.begin() ? --a.end() : prev(a_it));
        if (gcd(a_pre->second, a_nex->second) == 1) {
          toi.push_back({a_pre->first, a_nex->first});
        }
        a.erase(a_it);
        good.erase(it++);
        if (a.size() <= 1) break;
      }
      if (a.size() <= 1) break;
      int p = -1;
      for (auto [fi, se] : toi) {
        if (!removed.count(fi) && !removed.count(se)) {
          if (p != fi) good.insert({fi, se}), p = se;
        }
      }
    }
    if (a.size() == 1 && a.begin()->second == 1) res.push_back(a.begin()->first);
    cout << res.size() << ' ';
    for (auto& x : res) cout << x + 1 << " ";
    cout << '\n';
  }
}