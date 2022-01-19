#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  // cin.tie(nullptr)->sync_with_stdio(false);
  int T, l, r;
  cin >> T;
  vector<vector<int>> v(20), p(20);
  for (int i = 0; i <= 2e5; i++) {
    for (int j = 0; j < 20; j++) {
      if ((i & (1 << j)) == 0) {
        v[j].push_back(i);
      }
    }
  }
  for (auto& t : v) ranges::sort(t);
  auto f = [&]() {
    cin >> l >> r;
    ll mini = 1e9;
    for (int i = 0; (1 << i) <= r; i++) {
      int nex = (l & (1 << i)) + (1 << i);
      if ((l & (1 << i)) || nex <= r) {
        ll t1 = lower_bound(v[i].begin(), v[i].end(), l) - v[i].begin();
        int right = r;
        ll t2 = upper_bound(v[i].begin(), v[i].end(), right) - v[i].begin();
        mini = min(mini, t2 - t1);
      }
    }
    cout << mini << "\n";
  };
  while (T--) f();
}