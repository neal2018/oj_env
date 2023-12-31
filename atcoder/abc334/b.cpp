#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll floor_div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b != 0); }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll a, m, l, r;
  cin >> a >> m >> l >> r;
  // a + xm <= l
  // x <= (r - a) / m
  // y < (l - a) / m
  const auto x = floor_div(r - a, m);
  const auto y = floor_div(l - a - 1, m);
  cout << (x - y) << "\n";
}
