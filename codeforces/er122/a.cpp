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
    int t = n % 7, last = n % 10;
    if (t <= last) {
      n -= t;
    } else {
      n -= t - 7;
    }
    cout << n << "\n";
  }
}