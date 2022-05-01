#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll pos = find(a.begin(), a.end(), n) - a.begin();
  for (int i = pos - 1; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      cout << "NO\n";
      return 0;
    }
  }
  for (int i = pos + 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
