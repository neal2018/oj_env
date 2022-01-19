#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), k(m), sum(m), pre(m + 1), pre2(m + 1), check(m), check2(m), p(m), inv(m);
    vector<vector<ll>> b(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < m; i++) {
      cin >> k[i];
      b[i].resize(k[i]);
      for (auto& x : b[i]) cin >> x, sum[i] += x;
    }
    ranges::sort(a, greater());
    a.resize(m);
    reverse(a.begin(), a.end());
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return sum[x] * k[y] < sum[y] * k[x]; });
    ll invalid = 0;
    for (int i = 0; i < m; i++) inv[p[i]] = i;
    for (int i = 0; i < m; i++) {
      if (a[i] * k[p[i]] < sum[p[i]]) {
        invalid++;
        if (i < m - 1 && a[i + 1] * k[p[i]] >= sum[p[i]]) {
          check2[i]++;
        }
      }
      if (i > 0 && a[i - 1] * k[p[i]] < sum[p[i]]) {
        check[i]++;
      }
    }
    for (int i = 0; i < m; i++) pre[i + 1] = pre[i] + check[i], pre2[i + 1] = pre2[i] + check2[i];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < k[i]; j++) {
        ll f = invalid, n_sum = sum[i] - b[i][j], n_k = k[i] - 1;
        if (b[i][j] * k[i] > sum[i]) {
          ll l = 0, r = m;
          while (l < r) {
            ll mid = (l + r) / 2;
            if (n_sum * k[p[mid]] < sum[p[mid]] * n_k) {
              r = mid;
            } else {
              l = mid + 1;
            }
          }
          f -= pre2[inv[i]] - pre2[r];
          if (a[r] * n_k < n_sum) f++;
          if (a[r] * n_k >= n_sum && a[inv[i]] * k[i] < sum[i]) f--;
        } else if (b[i][j] * k[i] < sum[i]) {
          ll l = 1, r = m;
          while (l < r) {
            ll mid = (l + r) / 2;
            if (n_sum * k[p[mid]] < sum[p[mid]] * n_k) {
              r = mid;
            } else {
              l = mid + 1;
            }
          }
          f += pre[r] - pre[inv[i] + 1];
          if (a[r - 1] * n_k < n_sum) f++;
          if (a[r - 1] * n_k >= n_sum && a[inv[i]] * k[i] < sum[i]) f--;
        }
        cout << (f <= 0 ? '1' : '0');
      }
    }
    cout << "\n";
  }
}