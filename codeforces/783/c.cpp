#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  ll k = (2 * n + 1) / 3;
  cout << k << "\n";
  for (int i = 0, j = 0; i < k; i++) {
    cout << i + 1 << " " << j + 1 << "\n";
    j += 2;
    if (j >= k) j = 1;
  }
}
