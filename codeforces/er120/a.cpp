#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto f = [&]() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c) return true;
    if (b == a + c) return true;
    if (c == b + a) return true;
    if (a == b && c % 2 == 0) return true;
    if (a == c && b % 2 == 0) return true;
    if (c == b && a % 2 == 0) return true;
    return false;
  };
  for (; T--;) cout << (f() ? "YES\n" : "NO\n");
}