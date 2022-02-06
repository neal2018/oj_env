#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll A, B, n;
    cin >> A >> B >> n;
    vector<ll> a(A), b(B);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());
    if (A < n - n / 2) {
      cout << "-1\n";
      continue;
    }
    ll noisy = min(B, n / 2), quite = n - noisy;
    while (noisy > 0 && quite < A && b[noisy - 1] < a[quite]) {
      noisy--, quite++;
    }
    // cout << noisy << " " << quite << "\n";
    ll res = accumulate(a.begin(), a.begin() + quite, 0ll);
    res += accumulate(b.begin(), b.begin() + noisy, 0ll);
    cout << res << "\n";
  }
}