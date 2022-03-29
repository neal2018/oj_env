#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, p, k;
    cin >> n >> p >> k;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    vector<ll> sum(k);
    ll res = 0, need = 0;
    for (ll i = 0; i < n; i++) {
      if (i < k - 1) {
        need += a[i];
      } else {
        sum[i % k] += a[i];
        need = pre[(i + 1) % k] + sum[i % k];
      }
      if (need <= p) res = max(res, i + 1);
    }
    cout << res << "\n";
  }
}
