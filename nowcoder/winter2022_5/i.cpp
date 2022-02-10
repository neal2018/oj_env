#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n), b;
  for (auto& x : a) cin >> x;
  for (int i = 0; i < n - 1; i++) b.push_back(a[i + 1] - a[i]);
  sort(b.begin(), b.end());
  vector<ll> pre_b(n);
  for (int i = 0; i < n - 1; i++) pre_b[i + 1] = pre_b[i] + b[i];
  while (q--) {
    ll k, p;
    cin >> k >> p;
    ll pos = lower_bound(b.begin(), b.end(), k) - b.begin();
    ll maxi = pre_b[n - 1] - pre_b[pos] - (n - 1 - pos) * k;
    cout << (maxi < p ? "No\n" : "Yes\n");
  }
}
