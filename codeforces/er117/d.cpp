#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, a, b, x;
  cin >> T;
  auto f = [&]() {
    cin >> a >> b >> x;
    while (max(a, b) >= x && a && b) {
      if (b > a) swap(a, b);
      if (b == x || (a - x) % b == 0) return true;
      ll c = b - a % b;
      a = a % b, b = c;
    }
    return false;
  };
  while (T--) cout << (f() ? "YES\n" : "NO\n");
}