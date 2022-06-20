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
    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto i : views::iota(1, n)) {
      b[i] = a[i] - a[i - 1];
    }
    ll pos = 0, neg = 0;
    for (auto i : views::iota(1, n)) {
      auto x = b[i];
      if (x > 0) pos += abs(x);
      if (x < 0) neg += abs(x);
    }
    ll res = neg + pos;
    a[0] -= neg;
    res += abs(a[0]);
    cout << res << "\n";
  }
}
