#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      mp[x].push_back(i);
    }
    int res = -1e9;
    for (auto& [k, v] : mp) {
      int sz = (int)v.size();
      for (int i = 0; i < sz - 1; i++) {
        res = max(res, v[i] + n - v[i + 1]);
      }
    }
    cout << (res == -1e9 ? -1 : res) << "\n";
  }
}