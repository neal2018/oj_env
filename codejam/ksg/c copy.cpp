#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[5010];
ll pre[5010];
int mp[(int)(1e6 + 100)];
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cin >> n >> k;
    pre[0] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pre[i + 1] = pre[i] + a[i];
    }
    int ans = 1e9;
    for (int i = 0; i <= k; i++) mp[i] = -1;
    for (int i = 0; i <= n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        ll t = pre[i] - pre[j];
        if (t > k) break;
        if (mp[t] != -1) {
          mp[t] = min(mp[t], i - j);
        } else {
          mp[t] = i - j;
        }
      }
      for (int j = i; j < n; j++) {
        ll t = pre[j + 1] - pre[i];
        if (t > k) break;
        if (mp[k - t] != -1) {
          ans = min(ans, j - i + 1 + mp[k - t]);
        }
      }
    }
    if (mp[k] != -1) {
      ans = min(ans, mp[k]);
    }
    cout << "Case #" << ttt << ": " << (ans == 1e9 ? -1 : ans) << '\n';
  }
  return 0;
}