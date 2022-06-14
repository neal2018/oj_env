#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int a[2][2], r, c;
  cin >> r >> c, r--, c--;
  cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
  cout << a[r][c] << "\n";
}
