#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = a; i <= b; i++) {
    if (i % c == 0 && i >= c) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}