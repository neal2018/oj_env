#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto func = [&]() {
    ll n;
    cin >> n;
    n *= 2;
    ll a = 0;
    while (n % 2 == 0) n /= 2, a++;
    ll t, p;
    if (n > (1ll << a)) {
      t = (n - (1ll << a) - 1) / 2;
      p = (n + (1ll << a) - 1) / 2;
    } else {
      t = ((1ll << a) - n - 1) / 2;
      p = ((1ll << a) + n - 1) / 2;
    }
    ll k = p - t;
    cout << (k <= 1 ? -1 : k) << "\n";
    return;
  };
  int T;
  cin >> T;
  while (T--) func();
}
