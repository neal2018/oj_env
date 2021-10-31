#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  // auto solve = [&] {
  // };
  for (ll ttt = 1; ttt <= T; ttt++) {
    cin >> n >> k;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
      pre[i + 1] = pre[i] + a[i];
    }
    ll ans = 1e9;
    unordered_map<ll, ll> mp;
    mp.reserve(1024);
    for (ll i = 0; i <= n; i++) {
      for (ll j = i - 1; j >= 0; j--) {
        ll t = pre[i] - pre[j];
        if (t > k) break;
        if (mp.count(t)) {
          mp[t] = min(mp[t], i - j);
        } else {
          mp[t] = i - j;
        }
      }
      for (ll j = i; j < n; j++) {
        ll t = pre[j + 1] - pre[i];
        if (t > k) break;
        if (mp.count(k - t)) {
          ans = min(ans, j - i + 1 + mp[k - t]);
        }
      }
    }
    if (mp.count(k)) {
      ans = min(ans, mp[k]);
    }
    cout << "Case #" << ttt << ": " << (ans == 1e9 ? -1 : ans) << '\n';
  }
  return 0;
}