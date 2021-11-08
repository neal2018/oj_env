#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    if (n == 2) {
      cout << 0 << '\n';
      continue;
    }
    ll res = 0, ans = 1e18;
    for (ll i = n - 1; i > 0; i--) {
      res += abs(a[i] - a[i - 1]);
    }
    for (int i = 1; i < n - 1; i++) {
      ans =
          min(ans, res - (abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1])) + abs(a[i + 1] - a[i - 1]));
    }
    ans = min(ans, res - max(abs(a[0] - a[1]), abs(a[n - 2] - a[n - 1])));
    cout << ans << '\n';
  }
}