#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<ll> a(k);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<ll> b(k + 1);  // b[i]: total path if i and it's right go to n
    for (int i = k - 1; i >= 0; i--) {
      b[i] = b[i + 1] + n - a[i];
    }
    ll left = 0, right = k;
    while (left < right) {
      ll mid = (left + right) / 2;
      if (b[mid] < n) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    cout << k - right << '\n';
  }
}