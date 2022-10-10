#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX = 1e6;

ll get_sqrt(ll x) {
  ll l = 1, r = x;
  while (l < r) {
    ll mid = l + (r - l + 1) / 2;
    if ((__int128)mid * mid <= x) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  auto ask = [&](ll x, ll y) {
    if (x < 0 || y < 0 || x > MAX || y > MAX) return 1ll;
    cout << x << " " << y << endl;
    ll t;
    cin >> t;
    return t;
  };
  for (int _ = 0; _ < n; _++) {
    [&] {
      auto x = rng() % MAX, y = rng() % MAX;
      cout << x << " " << y << endl;
      ll t;
      cin >> t;
      if (t == 0) return;
      for (ll i = 0, X = t; i * i <= X; i++) {
        ll j2 = X - i * i;
        auto j = get_sqrt(j2);
        if (j * j == j2) {
          for (auto t1 : {1, -1}) {
            for (auto t2 : {1, -1}) {
              if (ask(x + t1 * i, y + t2 * j) == 0) return;
            }
          }
        }
      }
    }();
  }
}
