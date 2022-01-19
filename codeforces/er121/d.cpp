#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 0, x; i < n; i++) {
      cin >> x, a[x]++;
    }
    vector<ll> b;
    b.reserve(n);
    for (int i = 0; i <= n; i++) {
      if (a[i] != 0) b.push_back(a[i]);
    }
    ll sz = b.size();
    vector<ll> pre(sz + 1);
    for (ll i = 0; i < sz; i++) pre[i + 1] = pre[i] + b[i];
    ll mini = 1e18, MAX = 20;
    for (ll k1 = 0; k1 < MAX; k1++) {
      for (ll k2 = 0; k2 < MAX; k2++) {
        for (ll k3 = 0; k3 < MAX; k3++) {
          if ((1 << k1) + (1 << k2) + (1 << k3) - n < 0) continue;
          auto it = upper_bound(pre.begin(), pre.end(), 1 << k1);
          assert(it != pre.begin());
          if (it == pre.end()) {
            ll need = (1 << k1) + (1 << k2) + (1 << k3) - n;
            mini = min(mini, need);
            continue;
          }
          it--;
          ll need1 = (1 << k1) - (*it);
          ll got = *it;
          auto it2 = upper_bound(it, pre.end(), got + (1 << k2));
          it2--;
          ll need2 = (1 << k2) - (*it2 - got);
          ll got2 = *it2;
          ll need3 = (1 << k3) - (n - got2);
          if (need3 < 0) continue;
          ll need = need1 + need2 + need3;
          mini = min(mini, need);
        }
      }
    }
    cout << mini << "\n";
  }
}