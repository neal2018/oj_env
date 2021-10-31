#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x, MOD = 998244353;
  cin >> n >> x;
  vector<ll> v(10);
  v[x] = 1;
  for (int i = 1; i < n; i++) {
    auto t = v;
    cin >> x;
    for (int j = 0; j < 10; j++) v[j] = 0;
    for (int j = 0; j < 10; j++) {
      (v[(j + x) % 10] += t[j]) %= MOD;
      (v[(j * x) % 10] += t[j]) %= MOD;
    }
  }
  for (auto& tt : v) cout << tt << '\n';
}