#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n % 3 == 0) {
      cout << n / 3 << "\n";
    } else if (n % 3 == 1) {
      if (n == 1) {
        cout << "2\n";
      } else {
        cout << n / 3 + 1 << "\n";
      }
    } else {
      cout << n / 3 + 1 << "\n";
    }
  }
}
