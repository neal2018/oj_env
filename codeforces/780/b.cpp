#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<>());
    if (n == 1) {
      cout << (a[0] == 1 ? "YES\n" : "NO\n");
    } else {
      cout << (a[0] - a[1] <= 1 ? "YES\n" : "NO\n");
    }
  }
}
