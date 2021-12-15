#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      mp[x]++;
    }
    int res = 0;
    for (auto& [k, v] : mp) res = max(res, v);
    cout << res << '\n';
  }
}