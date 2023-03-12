#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int x) {
  int res = 0;
  while (x) res += x % 10, x /= 10;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      cout << n / 2 << " " << n / 2 << "\n";
      continue;
    }
    if (n % 10 != 9) {
      cout << n / 2 << " " << n / 2 + 1 << "\n";
      continue;
    }
    int cnt = 0, mul = 1, t = n;
    while (t % 10 == 9) {
      cnt++, t /= 10, mul *= 10;
    }
    int x = (t + 1) / 2 * mul, y = t / 2 * mul;
    int base = 0, pp = 1;
    for (int i = 0; i < cnt / 2; i++) base = base * 10 + 9, pp *= 10;
    if (cnt % 2 == 0) {
      x += base * pp;
      y += base;
    } else {
      x += base * pp * 10 + 4;
      y += base * 10 + 5;
    }
    cout << x << " " << y << "\n";
  }
}
