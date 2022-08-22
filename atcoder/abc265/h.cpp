#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  map<int, array<vector<int>, 2>> mp;
  for (int i = 0, x; i < 2 * n; i++) {
    cin >> x;
    int zero = __builtin_ctz(x);
    mp[x >> zero][i >= n].push_back(zero);
  }
  int res = 0;
  while (mp.size()) {
    auto [k, v] = *mp.rbegin();
    mp.erase(--mp.end());
    if (v[1].size() > v[0].size()) {
      cout << "-1\n";
      return 0;
    }
    sort(v[0].begin(), v[0].end(), greater<>());
    sort(v[1].begin(), v[1].end(), greater<>());
    while (v[0].size() > v[1].size()) {
      auto zero = v[0].back();
      v[0].pop_back();
      res += zero + 1;
      int extra = __builtin_ctz(k >> 1);
      mp[k >> (extra + 1)][0].push_back(extra);
    }
    for (int i = 0; i < v[0].size(); i++) {
      res += abs(v[0][i] - v[1][i]);
    }
  }
  cout << res << "\n";
}
