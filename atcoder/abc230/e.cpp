#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, res = 0;
  cin >> n;
  for (ll l = 1, r; l <= n; l = r + 1) {
    r = min(n, n / (n / l));
    res += n / l * (r - l + 1);
  }
  cout << res << "\n";
}