#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  int c = 0;
  for (int i : {4, 2, 1}) {
    if (a >= i || b >= i) {
      c += i;
      if (a >= i) a -= i;
      if (b >= i) b -= i;
    }
  }
  cout << c << "\n";
}
