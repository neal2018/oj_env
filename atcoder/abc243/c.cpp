#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  int n;
  map<int, vector<pair<int, int>>> mp;
  cin >> n;
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    mp[y].push_back({x, i});
  }
  string s;
  cin >> s;
  int f = 0;
  for (auto& [y, v] : mp) {
    int has_right = 0;
    sort(v.begin(), v.end());
    for (auto& [x, i] : v) {
      if (s[i] == 'R') {
        has_right = 1;
      } else if (has_right) {
        f = 1;
      }
    }
  }
  cout << (f ? "Yes\n" : "No\n");
}