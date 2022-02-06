#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll m;
  cin >> m;
  map<ll, ll> mp;
  vector<string> res(m);
  for (int i = 0; i < m; i++) {
    ll n;
    cin >> n;
    map<ll, vector<int>> freq;
    res[i] = string(n, '?');
    int l_cnt = 0;
    for (int j = 0, x; j < n; j++) cin >> x, (freq[x].push_back(j));
    for (auto& [k, v] : freq) {
      while (v.size() > 1) {
        int x = v.back();
        v.pop_back();
        int y = v.back();
        v.pop_back();
        res[i][x] = 'L', res[i][y] = 'R';
      }
      if (v.size()) {
        mp[k]++;
      }
    }
  }
  int f = 1;
  for (auto& [k, v] : mp) {
    if (v % 2) f = 0;
  }
  if (f) {
    cout << "YES\n";
    for (auto& s : res) cout << s << "\n";
  } else {
    cout << "NO\n";
  }
}
