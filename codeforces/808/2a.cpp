#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    auto t = a[0];
    for (auto& x : a) t = gcd(t, x);
    cout << ((t == ranges::min(a) && t == a[0]) ? "YES\n" : "NO\n");
  }
}
