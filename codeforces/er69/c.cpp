#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> diff(n - 1);
  for (int i = 0; i < n - 1; i++) {
    diff[i] = a[i + 1] - a[i];
  }
  sort(diff.begin(), diff.end());
  cout << accumulate(diff.begin(), diff.begin() + n - k, 0ll) << "\n";
}
