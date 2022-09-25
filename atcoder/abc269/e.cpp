#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto ask = [](int a, int b, int c, int d) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
    int res = 0;
    cin >> res;
    return res;
  };
  int n;
  cin >> n;
  auto x = [&] {
    auto check = [&](int mid) { return ask(0, mid, 0, n - 1) == mid; };
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }();
  auto y = [&] {
    auto check = [&](int mid) { return ask(0, n - 1, 0, mid) == mid; };
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }();
  cout << "! " << x + 1 << " " << y + 1 << "\n";
}
