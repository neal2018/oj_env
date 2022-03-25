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
    if (a == vector<ll>(n, a[0])) return true;
    if (find(a.begin(), a.end(), 1) == a.end()) return true;
    if (find(a.begin(), a.end(), 0) != a.end()) return false;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    ll sz = a.size();
    for (int i = 0; i < sz - 1; i++) {
      if (a[i + 1] - a[i] == 1) return false;
    }
    return true;
  };
  while (T--) {
    ll f = func();
    cout << (f ? "YES\n" : "NO\n");
  }
}
