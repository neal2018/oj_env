#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x;
  cin >> x;
  // constexpr ll MAX = 1e5;
  vector<ll> a;
  a.reserve(1e4);
  auto check = [&](ll k) {
    auto t = to_string(k);
    ll n = t.size();
    if (n <= 2) return true;
    auto diff = t[0] - t[1];
    for (int i = 0; i < n - 1; i++) {
      if (t[i] - t[i + 1] != diff) return false;
    }
    return true;
  };
  for (ll i = 0; i < (ll)1e6; i++) {
    if (check(i) != 0) a.push_back(i);
  }
  for (int i = 6; i <= 18; i++) {
    for (int j = 1; j <= 9; j++) {
      if (j - i + 1 >= 0) {
        ll cur = 0;
        for (int k = 0; k < i; k++) {
          cur = cur * 10 + j - k;
        }
        a.push_back(cur);
      }
      {
        ll cur = 0;
        for (int k = 0; k < i; k++) {
          cur = cur * 10 + j;
        }
        a.push_back(cur);
      }
      if (j + i - 1 <= 9) {
        ll cur = 0;
        for (int k = 0; k < i; k++) {
          cur = cur * 10 + j + k;
        }
        a.push_back(cur);
      }
    }
  }
  cout << *lower_bound(a.begin(), a.end(), x) << "\n";
}