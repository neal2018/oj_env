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
    vector<pair<ll, int>> a(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    ranges::sort(a, greater());
    ll res = 0;
    for (int i = 0, f = 1; i < n; i++, f = -f) {
      auto [k, p] = a[i];
      res += k * (1 + i / 2);
      pos[p] = f * (1 + i / 2);
    }
    cout << res * 2 << "\n0 ";
    for (auto& x : pos) cout << x << ' ';
    cout << '\n';
  }
}