#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  unordered_map<ll, ll> mp;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    ll x = 0;
    for (int j = 0, c; j < k; j++) {
      cin >> c;
      x <<= 2;
      x |= c;
    }
    mp[x] = i;
    a[i] = x;
  }
  unordered_map<ll, ll> cnt;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll need = 0;
      for (int t = 0; t < k; t++) {
        ll x = (a[i] >> (2 * (k - t - 1))) & 3;
        ll y = (a[j] >> (2 * (k - t - 1))) & 3;
        ll z = (x == y ? x : (3 - x - y));
        need <<= 2;
        need |= z;
      }
      if (mp.count(need)) cnt[need]++;
    }
  }
  ll res = 0;
  for (auto [kk, v] : cnt) {
    res += v * (v - 1) / 2;
  }
  cout << res << "\n";
}
