#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, a, b;
    cin >> n >> a >> b;
    string repeat, res;
    for (int i = 0; i < b; i++) {
      repeat += (i + 'a');
    }
    repeat += string(a - repeat.size(), b - 1 + 'a');
    while (n >= a) {
      res += repeat, n -= a;
    }
    res += repeat.substr(0, n);
    cout << res << "\n";
  }
}
