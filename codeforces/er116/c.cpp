#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
ll T, n, inf = 1e9;
void solve() {
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  k += 1;
  ll ans = 0;
  ll i = 0;
  for (; i < n - 1 && k > 0; i++) {
    ll base = 1;
    for (int j = 0; j < a[i]; j++) base *= 10;
    ll nex_base = 1;
    for (int j = 0; j < a[i + 1]; j++) nex_base *= 10;
    ll cnt = min(k, nex_base / base - 1);
    k -= cnt;
    ans += cnt * base;
  }
  if (k > 0) {
    ll base = 1;
    for (int j = 0; j < a[n - 1]; j++) base *= 10;
    ans += base * k;
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> T;
  while (T--) {
    solve();
  }
}