#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<ll, 2>> a;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        a.push_back({i, 0});
        while (n % i == 0) {
          a.back()[1]++;
          n /= i;
        }
      }
    }
    if (n != 1) a.push_back({n, 1});
    ll res = 0;
    while (true) {
      ll cur = 1;
      ll mul = 1e9;
      for (auto& [x, y] : a) {
        if (y > 0) {
          cur *= x, mul = min(mul, y);
        }
      }
      if (cur == 1) break;
      res += cur * mul;
      for (auto& [x, y] : a) {
        if (y > 0) {
          y -= mul;
        }
      }
    }
    cout << res << "\n";
  }
}