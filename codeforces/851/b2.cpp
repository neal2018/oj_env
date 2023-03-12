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
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    while (true) {
      int x = rng() % (n + 1);
      int y = n - x;
      if (abs(f(x) - f(y)) <= 1) {
        cout << x << " " << y << "\n";
        break;
      }
    }
  }
}
