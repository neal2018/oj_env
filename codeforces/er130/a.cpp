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
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    cout << max(0ll, accumulate(a.begin(), a.end(), 0ll) - m) << '\n';
  }
}
