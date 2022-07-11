#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = a + b + c + d;
    if (t == 0) {
      cout << "0\n";
    } else if (t == 4) {
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
}
