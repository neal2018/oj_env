#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto f = [&]() -> ll {
    ll n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) return 0;
    if (n > m) swap(n, m);
    if (n == 1 && m > 2) return -1;
    ll comm = min(n - 1, m - 1), remain = m - 1 - comm;
    return comm * 2 + remain + remain / 2 * 2;
  };
  int T;
  cin >> T;
  while (T--) {
    cout << f() << "\n";
  }
}
