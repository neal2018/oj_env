#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b;
    cin >> a >> b;
    if (a == 0) {
      cout << 1 << "\n";
    } else {
      cout << a + 2 * b + 1 << "\n";
    }
  }
}
