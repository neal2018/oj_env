#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll x;
  cin >> x;
  ll k = 0;
  while ((1 << k) <= x) k++;
  cout << (x << k) + x << "\n";
}
