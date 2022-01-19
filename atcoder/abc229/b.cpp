#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  for (; a && b; a /= 10, b /= 10) {
    int x = a % 10, y = b % 10;
    if (x + y >= 10) {
      cout << "Hard\n";
      return 0;
    }
  }
  cout << "Easy\n";
}