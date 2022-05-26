#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto to_base = [&](int x, int k) {
    vector<int> res;
    while (x) {
      res.push_back(x % k), x /= k;
    }
    return res;
  };
  auto minus = [&](int x, int y, int k) {
    auto xx = to_base(x, k), yy = to_base(y, k);
    ll len = max(xx.size(), yy.size());
    xx.resize(len), yy.resize(len);
    for (int i = 0; i < len; i++) {
      xx[i] = (xx[i] - yy[i] + k) % k;
    }
    ll res = 0;
    for (ll i = len - 1; i >= 0; i--) {
      res = res * k + xx[i];
    }
    return res;
  };
  auto f = [&]() {
    int n, k;
    cin >> n >> k;
    int reply;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << 0 << endl;
      } else if (i % 2) {
        cout << minus(i - 1, i, k) << endl;
      } else {
        cout << minus(i, i - 1, k) << endl;
      }
      cin >> reply;
      if (reply == 1) return;
    }
  };
  while (T--) f();
}
