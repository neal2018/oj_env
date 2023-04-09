#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  ll addon = 0;
  vector<ll> power(n, 1);
  for (int i = 1; i < n; i++) power[i] = power[i - 1] * 2 % MOD;
  for (; n > 1; n--) {
    ll mini = a[0];
    addon += (power[n - 1] * mini) % MOD;
    ll sz = min(64, n);
    vector<ll> can;
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz && i * j < sz; j++) {
        can.push_back(a[i] + a[j] - 2 * mini);
      }
    }
    sort(can.begin(), can.end());
    can.resize(min(64, n - 1));
    a = can;
  }
  cout << (a[0] + addon) % MOD << "\n";
}
