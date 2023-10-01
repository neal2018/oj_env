#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, p;
  cin >> n >> k >> p;

  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    auto check = [&](ll t) {
      if (t <= k && n / t <= p) res.push_back(t);
    };
    if (n % i == 0) {
      check(i);
      if (i * i != n) check(n / i);
    }
  }
  sort(res.begin(), res.end());
  cout << res.size() << "\n";
  for (auto& x : res) cout << x << "\n";
}
