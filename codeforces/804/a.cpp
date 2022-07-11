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
    if (n % 2) {
      cout << "-1\n";
    } else {
      cout << n / 2 << " 0 0\n";
    }
  }
}
