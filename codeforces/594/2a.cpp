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
  auto get = [&] {
    ll n;
    cin >> n;
    ll n_odd = 0, n_even = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x, ((x & 1) ? n_odd : n_even)++;
    }
    return pair{n_odd, n_even};
  };
  while (T--) {
    auto [a, b] = get();
    auto [c, d] = get();
    cout << a * c + b * d << "\n";
  }
}
