#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (int i = 1, x; i < n; i++) {
      cin >> x, x--;
      g[x].push_back(i);
    }
    vector<ll> a{1};
    for (auto& v : g) {
      if (v.size()) a.push_back(v.size());
    }
    sort(a.begin(), a.end());
    vector<ll> b;
    for (int i = 0; i < a.size(); i++) {
      a[i] -= i + 1;
      if (a[i] > 0) b.push_back(a[i]);
    }
    sort(b.begin(), b.end());

    auto check = [&](ll mid) {
      ll need = 0;
      for (auto& x : b) need += max(0ll, x - mid);
      return need <= mid;
    };
    ll l = 0, r = 1e5 + 10;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r + a.size() << "\n";
  }
}
