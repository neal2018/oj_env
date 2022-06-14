#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end(), greater<ll>());
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << (pre[x] - pre[x - y]) << "\n";
  }
}
