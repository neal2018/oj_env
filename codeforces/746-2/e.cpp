#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  for (int k = 0, x = 0; k < 20; k++, x = 0) {
    unordered_map<int, int> mp = {{0, -1}};
    for (int i = 0; i < n; i++) {
      if (a[i] >> k & 1) {
        x ^= (a[i] >> k);
        mp.count(x) ? (ans = max(ans, i - mp[x])) : (mp[x] = i);
      } else {
        mp = {{0, i}}, x = 0;
      }
    }
  }
  cout << ans << '\n';
}