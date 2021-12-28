#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<string> s(n);
    for (auto& x : s) cin >> x;
    ll res = -1e9;
    vector<int> order(m), p(m), ans(m);
    iota(order.begin(), order.end(), 0);
    for (int t = 0; t < (1 << n); t++) {
      vector<ll> diff(m);
      for (int i = 0; i < n; i++) {
        if (t & (1 << i)) {
          for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') diff[j]++;
          }
        } else {
          for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') diff[j]--;
          }
        }
      }
      sort(order.begin(), order.end(), [&](int x, int y) { return diff[x] > diff[y]; });
      for (int i = 0; i < m; i++) {
        p[order[i]] = m - i;
      }
      ll f = 1, acc = 0;
      for (int i = 0; i < n && f; i++) {
        ll r = 0;
        for (int j = 0; j < m; j++) {
          if (s[i][j] == '1') r += p[j];
        }
        if (t & (1 << i)) {
          if (r < a[i]) f = 0;
        } else {
          if (r > a[i]) f = 0;
        }
        acc += abs(r - a[i]);
      }
      if (f && acc > res) {
        res = acc, ans = p;
      }
    }
    for (auto& x : ans) cout << x << " ";
    cout << "\n";
  }
}
