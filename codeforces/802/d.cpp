#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), pre(n + 1), min_t(n);
  for (auto& x : a) cin >> x;
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  for (ll i = 0, mini = 0; i < n; i++) {
    mini = max(mini, (pre[i + 1] + i) / (i + 1));
    min_t[i] = -max(mini, (pre[n] + i) / (i + 1));
  }
  int q;
  cin >> q;
  while (q--) {
    ll t;
    cin >> t;
    auto it = lower_bound(min_t.begin(), min_t.end(), -t);
    if (it == min_t.end()) {
      cout << -1 << "\n";
    } else {
      cout << it - min_t.begin() + 1 << "\n";
    }
  }
}
