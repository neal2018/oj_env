#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr ld eps = 1e-14;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  ld res = 3.5;
  for (int i = 1; i < n; i++) {
    ld cur = 0;
    for (int j = 1; j <= 6; j++) {
      if (j < res) {
        cur += res;
      } else {
        cur += j;
      }
    }
    cur /= 6;
    res = cur;
  }
  cout << res << "\n";
}
