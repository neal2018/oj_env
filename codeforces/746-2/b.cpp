#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, t;
  cin >> T;
  while (T--) {
    cin >> n >> t;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    auto b = a;
    sort(b.begin(), b.end());
    bool f = true;
    for (int i = 0; i < n && f; i++) {
      if (n - 1 - i < t && i < t && a[i] != b[i]) f = false;
    }
    f ? (cout << "YES\n") : (cout << "NO\n");
  }
}