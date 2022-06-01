#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll x, y, k;
    cin >> x >> y >> k;
    ll need = (y + 1) * k;
    cout << (need - 1 + x - 2) / (x - 1) + k << "\n";
  }
}
