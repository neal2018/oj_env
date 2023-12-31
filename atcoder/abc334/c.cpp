#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(k);
  for (auto& x : a) cin >> x;
  ll cur = 0;
  for (int i = 0; i < k; i += 2) {
    if (i + 1 > k - 1) break;
    cur += a[i + 1] - a[i];
  }
  ll res = cur;
  if (k % 2 == 0) {
    cout << res << "\n";
    return 0;
  }
  for (ll i = k - 3; i >= 0; i -= 2) {
    cur = cur - (a[i + 1] - a[i]) + (a[i + 2] - a[i + 1]);
    res = min(res, cur);
  }
  cout << res << "\n";
}
