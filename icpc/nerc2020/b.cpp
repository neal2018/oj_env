#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  map<int, int> mp;
  for (int x, i = 0; i < n; i++) {
    cin >> x, x--, mp[x]++;
  }
  vector<ll> a;
  for (auto& [_, v] : mp) a.push_back(v);
  ll maxi = *max_element(a.begin(), a.end());
  sort(a.begin(), a.end());
  n = a.size();
  ll res = 1e18;
  for (ll s = (n + 1) / 2; s <= n; s++) {
    auto check = [&](ll mid) {
      ll l = 0, r = n, need = 0;
      while (l < r) {
        if (a[l] + a[r - 1] <= mid) {
          l++, r--;
        } else {
          r--;
        }
        need++;
      }
      return need <= s;
    };
    ll l = maxi, r = 2 * maxi;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    res = min(res, r * s);
  }
  cout << res << "\n";
}
