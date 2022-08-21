#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SIZE = 30;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  for (int bit = SIZE; bit >= 0; bit--) {
    auto get = [&](ll x) { return ((x >> bit) << bit) | (1 << bit); };
    vector<ll> nex, need;
    for (auto& x : a) {
      if ((x >> bit) & 1) {
        nex.push_back(x);
      } else {
        need.push_back(get(x) - x);
      }
    }
    if (nex.size() >= k) {
      a = nex;
      res |= (1 << bit);
    } else {
      sort(need.begin(), need.end());
      ll remain = k - nex.size(), require = 0;
      for (int i = 0; i < remain; i++) require += need[i];
      if (require <= m) {
        m -= require;
        for (int i = 0; i < remain; i++) nex.push_back(1 << bit);
        a = nex;
        res |= (1 << bit);
      }
    }
  }
  cout << res << "\n";
}
