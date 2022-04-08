#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll HASH = 3000;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<string> res(n, string(n, 'G'));
  vector<ll> pos(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0, x; j < n; j++) {
      cin >> x;
      pos[x - 1] = i * HASH + j;
    }
  }
  set<ll> plus, neg;
  for (ll i = n * n - 1; i >= 0; i--) {
    ll x = pos[i] / HASH, y = pos[i] % HASH;
    int f = 1;
    if (plus.size()) {
      auto mini_plus = *plus.begin(), maxi_plus = *plus.rbegin();
      auto mini_neg = *neg.begin(), maxi_neg = *neg.rbegin();
      if (abs(mini_plus - (x + y)) > k || abs(maxi_plus - (x + y)) > k ||
          abs(mini_neg - (x - y)) > k || abs(maxi_neg - (x - y)) > k) {
        f = 0;
      }
    }
    if (f) {
      res[x][y] = 'M';
      plus.insert(x + y), neg.insert(x - y);
    }
  }
  for (auto& x : res) cout << x << "\n";
}
