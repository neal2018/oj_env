#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), s(k);
  for (auto& x : a) cin >> x;
  for (auto& x : s) cin >> x;
  vector<vector<int>> res(k);

  vector<int> order(k);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) { return s[i] < s[j]; });
  for (auto i : order) {
    if (i == order.back()) break;
    int need = s[i];
    vector from(need + 1, vector<int>(need, -1));
    from[0][0] = -2;
    for (int id = 0; id < n; id++) {
      auto& x = a[id];
      if (x == 0) continue;
      for (int cnt = need - 1; cnt >= 0; cnt--) {
        for (int remainder = 0; remainder < need; remainder++) {
          auto& to = from[(cnt + 1)][(remainder + x) % need];
          if (from[cnt][remainder] == -1 || to != -1) continue;
          to = id;
        }
      }
    }
    assert(from[need][0] != -1);
    for (int cnt = need, remainder = 0; cnt > 0; cnt--) {
      auto& x = a[from[cnt][remainder]];
      res[i].push_back(x);
      remainder = ((remainder - x) % need + need) % need;
      x = 0;
    }
    assert(accumulate(res[i].begin(), res[i].end(), 0ll) % s[i] == 0);
  }
  int last = order.back();
  ll sum = 0;
  for (auto& x : a) {
    if (x != 0) res[last].push_back(x), sum += x;
  }
  ll addon = s[last] - (sum % s[last]);
  res[last].push_back(addon);
  cout << addon << "\n";
  for (auto& v : res) {
    for (auto& x : v) cout << x << " ";
    cout << "\n";
  }
}
