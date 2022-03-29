#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c, r;
    cin >> a >> b >> c >> r;
    if (b < a) swap(a, b);
    ll res = b - a;
    ll start = max(a, c - r), ending = min(b, c + r);
    res -= max(0ll, ending - start);
    cout << res << "\n";
  }
}
