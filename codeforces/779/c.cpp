#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto func = [&]() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    auto it = find(a.begin(), a.end(), 1);
    if (it == a.end()) return false;
    rotate(a.begin(), it, a.end());
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] > 1 || a[i] == 1) return false;
    }
    return true;
  };
  while (T--) {
    cout << (func() ? "YES\n" : "NO\n");
  }
}
