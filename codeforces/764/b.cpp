#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto f = [&]() {
    ll a, b, c;
    cin >> a >> b >> c;
    // a+c=2b
    if ((2 * b - c) > 0 && (2 * b - c) % a == 0) return true;
    if ((2 * b - a) > 0 && (2 * b - a) % c == 0) return true;
    if ((a + c) > 0 && (a + c) % 2 == 0 && ((a + c) / 2) % b == 0) return true;
    return false;
  };
  while (T--) cout << (f() ? "YES\n" : "NO\n");
}