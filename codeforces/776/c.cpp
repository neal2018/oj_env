#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> a(m);
    for (int i = 0; i < m; i++) {
      auto& [x, y, z] = a[i];
      cin >> y >> x, z = i;
    }
    sort(a.begin(), a.end());
    a.resize(2 * n);
    sort(a.begin(), a.end(), [](const auto& a1, const auto& a2) { return a1[1] < a2[1]; });
    ll res = accumulate(a.begin(), a.end(), 0ll,
                        [](const auto& a1, const auto& a2) { return a1 + a2[0]; });
    cout << res << "\n";
    for (int i = 0; i < n; i++) {
      cout << a[i][2] + 1 << " " << a[2 * n - 1 - i][2] + 1 << "\n";
    }
  }
}
