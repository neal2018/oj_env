#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
#define ld long double
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto& x : a) {
      cin >> x;
      sum += x;
    }
    if ((2 * sum) % n != 0) {
      cout << 0 << '\n';
      continue;
    }
    ll mean2 = 2 * sum / n;
    unordered_map<ll, ll> mp;
    mp.reserve(1024);
    // mp.max_load_factor(0.25);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll need = mean2 - a[i];
      if (mp.count(need)) {
        ans += mp[need];
      }
      mp[a[i]]++;
    }
    cout << ans << '\n';
  }
}