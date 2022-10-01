#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto f = [](int x) -> char { return char(x < 10 ? '0' + x : ('A' + x - 10)); };
  cout << f(n / 16) << f(n % 16) << "\n";
}
