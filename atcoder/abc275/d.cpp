#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  unordered_map<ll, ll> mp;
  ll n;
  cin >> n;
  function<ll(ll)> f = [&](ll x) {
    if (mp.count(x)) return mp[x];
    if (x == 0) return 1ll;
    return mp[x] = f(x / 2) + f(x / 3);
  };
  auto res = f(n);
  cout << res << "\n";
}
