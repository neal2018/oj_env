#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    map<ll, ll> mp;
    for (auto& x : a) mp[x]++;
    ll q;
    cin >> q;
    while (q--) {
      auto res = [&]() -> ll {
        ll x, y;
        cin >> x >> y;
        auto a_minus_b_2 = i128(x) * x - 4 * y;
        if (a_minus_b_2 < 0) return 0;
        auto root = max(i128(sqrt((long double)a_minus_b_2)) - 20, i128(0));
        while (root * root < a_minus_b_2) root++;
        if (root * root != a_minus_b_2) return 0;
        auto a2 = x + root;
        auto b2 = x - root;
        if (a2 % 2 != 0) return 0;
        if (b2 % 2 != 0) return 0;
        auto a = a2 / 2;
        auto b = b2 / 2;
        if (a + b != x || a * b != y) return 0;
        if (a == b) return mp[a] * (mp[a] - 1) / 2;
        return mp[a] * mp[b];
      }();
      cout << res << " ";
    }
    cout << "\n";
  }
}
