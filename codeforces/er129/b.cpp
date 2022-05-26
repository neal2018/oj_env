#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    cin >> m;
    vector<ll> b(m);
    for (auto& x : b) cin >> x;
    ll sum = accumulate(b.begin(), b.end(), 0ll);
    cout << a[sum % n] << "\n";
  }
}
