#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  multiset<array<int, 3>> st;  // [-r, l, i]
  vector<array<int, 3>> seg;
  seg.reserve(2 * n);
  for (int i = 0; i < n; i++) {
    seg.push_back({a[i].first, -1, i});
    seg.push_back({a[i].second, 1, i});
  }
  sort(seg.begin(), seg.end());
  vector<int> res;
  for (auto& [pos, is_new, i] : seg) {
    auto [l, r] = a[i];
    if (is_new == -1) {
      st.insert({-r, l, i});
      if (st.size() > k) {
        res.push_back((*st.begin())[2]);
        st.erase(st.begin());
      }
    } else {
      if (st.find({-r, l, i}) != st.end()) st.erase(st.find({-r, l, i}));
    }
  }
  cout << res.size() << "\n";
  for (auto& x : res) cout << x + 1 << " ";
  cout << "\n";
}
