#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int x;
  cin >> x;
  int a = x % 10, b = (x / 10) % 10, c = x / 100;
  cout << 111 * (a + b + c) << "\n";
}