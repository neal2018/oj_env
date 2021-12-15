#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 998244353;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  auto func = [&]() {
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    ll cur = -1;
    for (int i = 0; i < n - 1; i++) {
      if (cur == -1) {
        cur = a[i + 1] - a[i];
      } else {
        cur = gcd(cur, a[i + 1] - a[i]);
      }
    }
    for (int i = 0; i < n; i++)
      if (abs(k - a[i]) % cur == 0) return true;
    return false;
  };
  while (T--) cout << (func() ? "YES\n" : "NO\n");
}