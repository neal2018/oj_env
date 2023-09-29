#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    ll l = 1, r = 3e9 + 10;
    auto check = [&](ll mid) {
      ll res = 0;
      for (auto x : a) res += max(mid - x, 0ll);
      return res <= s;
    };
    while (l < r) {
      const auto mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }
}
