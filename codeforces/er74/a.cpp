#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    cout << ((x - y) == 1 ? "NO\n" : "YES\n");
  }
}
