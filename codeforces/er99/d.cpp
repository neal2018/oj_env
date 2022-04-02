#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  auto func = [&]() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll cnt = 0;
    if (is_sorted(a.begin(), a.end())) return cnt;
    for (int i = 0; i < n; i++) {
      if (k < a[i]) swap(k, a[i]), cnt++;
      if (is_sorted(a.begin(), a.end())) return cnt;
    }
    return -1ll;
  };
  while (T--) {
    cout << func() << "\n";
  }
}