#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> pre(n);
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i - 1];
    if (i > 0 && i % 2 == 0) pre[i] += a[i] - a[i - 1];
  }

  auto query = [&](ll x) {
    auto pos = int(--upper_bound(a.begin(), a.end(), x) - a.begin());
    ll res = pre[pos];
    if (pos % 2 == 1) res += x - a[pos];
    return res;
  };

  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << query(r) - query(l) << "\n";
  }
}
