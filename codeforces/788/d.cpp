#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll MAX = 1e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<ll> a(MAX);
  a[2] = 2, a[3] = 6;
  ll t = 2;
  for (int i = 4; i + 2 < MAX; i += 3) {
    a[i] = a[i - 1] + 2 * t;
    a[i + 1] = a[i] + 2 * (t + 1);
    a[i + 2] = a[i + 1] + 2 * (t + 2);
    t += 2;
  }
  // cout << a.back();
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    auto tt = lower_bound(a.begin(), a.end(), n);
    cout << (tt - a.begin()) << "\n";
  }
}
