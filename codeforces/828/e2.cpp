#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    auto get_factor = [&](ll t) {
      vector<ll> factor;
      for (ll i = 1; i * i <= t; i++) {
        if (t % i == 0) {
          factor.push_back(i);
          factor.push_back(t / i);
          ;
        }
      }
      sort(factor.begin(), factor.end());
      factor.erase(unique(factor.begin(), factor.end()), factor.end());
      return factor;
    };
    auto af = get_factor(a);
    auto bf = get_factor(b);
    vector<ll> factor;
    for (auto& x : af) {
      for (auto& y : bf) {
        if ((a * b) % (x * y) == 0) {
          factor.push_back(x * y);
          factor.push_back(((a * b) / (x * y)));
        }
      }
    }
    sort(factor.begin(), factor.end());
    factor.erase(unique(factor.begin(), factor.end()), factor.end());

    [&] {
      for (auto& t : factor) {
        ll need = lcm(t, a * b) / t;
        ll x = c / need * need;
        ll y = d / t * t;
        if (x > a && y > b) {
          cout << x << " " << y << "\n";
          // cout << ((x * y) % (a * b)) << "\n";
          return;
        }
      }
      cout << "-1 -1\n";
    }();
  }
}
