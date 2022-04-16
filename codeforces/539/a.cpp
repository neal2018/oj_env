#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  map<ll, ll> odd{{0, 1}}, even;
  ll res = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    cur ^= a[i];
    auto& v = (i & 1) ? odd : even;
    res += v[cur];
    v[cur]++;
  }
  cout << res << "\n";
}
