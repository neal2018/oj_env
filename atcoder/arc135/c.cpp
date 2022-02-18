#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr int MAX = 31;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> one(MAX), zero(MAX);
  for (auto& x : a) {
    for (int i = 0; i < MAX; i++) {
      if (x >> i & 1) {
        one[i]++;
      } else {
        zero[i]++;
      }
    }
  }
  ll res = accumulate(a.begin(), a.end(), 0ll);
  for (auto& x : a) {
    ll sum = 0;
    for (int i = 0; i < MAX; i++) {
      if (x >> i & 1) {
        sum += (1 << i) * zero[i];
      } else {
        sum += (1 << i) * one[i];
      }
    }
    res = max(res, sum);
  }
  cout << res << "\n";
}
