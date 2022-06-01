#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int a, b, c;
  cin >> a >> b >> c;
  tie(a, c) = minmax({a, c});
  if (a <= b && b <= c) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
