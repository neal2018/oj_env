#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    ll sum = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      sum += x;
    }
    if (sum >= n) {
      cout << sum - n << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}