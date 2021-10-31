#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    n--;
    ll x = 1, cnt = 0;
    while (x < k && n > 0) {
      cnt++;
      n -= x;
      x = min(2 * x, k);
      // cout << x << endl;
    }
    if (n > 0) {
      cnt += (n + k - 1) / (k);
    }
    cout << cnt << '\n';
  }
}