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
    ll n;
    cin >> n;
    if (n == 1) {
      cout << "0\n";
    } else if (n == 2) {
      cout << "1\n";
    } else if (n == 3) {
      cout << "2\n";
    } else if (n % 2 == 0) {
      cout << "2\n";
    } else {
      cout << "3\n";
    }
  }
}
