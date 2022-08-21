#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    vector<ll> a(n), pre_a(n + 1);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) pre_a[i + 1] = pre_a[i] + a[i];
    int m;
    cin >> m;
    vector<ll> b(m), pre_b(m + 1);
    for (auto& x : b) cin >> x;
    for (int i = 0; i < m; i++) pre_b[i + 1] = pre_b[i] + b[i];

    int k;
    cin >> k;
    auto get = [&](vector<ll>& pre_v, ll pick, ll sz) {
      ll need = sz - pick, res = 9e18;
      // [i, i+need)
      if (need == 0) return pre_v[sz];
      for (int i = 0; i + need <= sz; i++) {
        res = min(res, pre_v[i + need] - pre_v[i]);
      }
      return pre_v[sz] - res;
    };

    ll res = 0;
    // i <= n , k-i <= m
    for (int i = max(0, k - m); i <= min(n, k); i++) {
      ll cur = get(pre_a, i, n) + get(pre_b, k - i, m);
      res = max(res, cur);
    }

    cout << res << "\n";
  }
}
