#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll t;
  cin >> t;
  auto f = [](ll x) { return x * x + 2 * x + 3; };
  cout << f(f(f(t) + t) + f(f(t))) << "\n";
}