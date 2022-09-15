#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll t = 1;
    while (t <= n) t *= 2;
    vector<ll> res(n);
    int cur = 0, i = 1;
    for (i = 1; i <= n / 2; i++) {
      if (cur >= n || cur + 2 >= n) break;
      res[cur] = i, res[cur + 2] = (t ^ i);
      cur += 4;
    }
    cur = 1;
    for (; i <= n / 2; i++) {
      if (cur >= n || cur + 2 >= n) break;
      res[cur] = i, res[cur + 2] = (t ^ i);
      cur += 4;
    }
    if (n % 4 == 2) {
      res[0] ^= 2 * t, res.back() ^= 2 * t;
    } else if (n % 4 == 3) {
      res[n - 2] = t;
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
