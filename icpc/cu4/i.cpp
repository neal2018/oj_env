#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 100007;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll a = 1, b = 1;
  for (int i = 1; i < 2 * n - 1; i++) {
    ll c = (a + b) % MOD;
    b = a, a = c;
  }
  cout << (n * b) % MOD << "\n";
}
