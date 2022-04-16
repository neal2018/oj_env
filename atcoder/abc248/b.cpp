#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll a, b, k;
  cin >> a >> b >> k;
  ll res = 0;
  while (a < b) {
    res++, a *= k;
  }
  cout << res << "\n";
}
