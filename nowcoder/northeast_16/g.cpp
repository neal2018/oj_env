#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q, t_min, t_max;
  cin >> n >> q >> t_min >> t_max;
  deque<pair<ll, ll>> dq;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    dq.push_back({x, 1});
  }
  ll delta = t_max - t_min + 1, timestamp = 0;
  while (q--) {
    ll t, k;
    cin >> t >> k;
    timestamp += t;
    ll sum = 0;
    ll new_add = (t_max - t_min + timestamp) % delta + t_min;
    dq.push_front({new_add, k});
    while (k) {
      auto [val, cnt] = dq.back();
      ll subtract = min(k, cnt);
      dq.back().second -= subtract;
      if (dq.back().second == 0) dq.pop_back();
      k -= subtract;
      ll cur = ((val - t_min - timestamp) % delta + delta) % delta + t_min;
      sum += subtract * cur;
    }
    cout << sum << "\n";
  }
}
