#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
constexpr ll MOD = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (m > n * (n - 1) / 2) {
      return false;
    }
    if (m < n - 1) return false;
    ll mini = 2;
    if (m == n * (n - 1) / 2) mini = 1;
    if (n == 1) mini = 0;
    return k - 1 > mini;
  };
  for (; T--;) cout << (f() ? "YES\n" : "NO\n");
}