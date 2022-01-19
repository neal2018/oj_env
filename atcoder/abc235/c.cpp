#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  map<int, vector<int>> mp;
  cin >> n >> q;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    mp[x].push_back(i);
  }
  int x, k;
  while (q--) {
    cin >> x >> k;
    if (mp.count(x) && mp[x].size() >= k) {
      cout << mp[x][k - 1] << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}