#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    string s;
    cin >> n >> m >> s;
    vector<ll> pre(n * m + 1);
    for (int i = 0; i < n * m; i++) pre[i + 1] = pre[i] + (s[i] == '1');
    vector<ll> row_cnt(n * m), col_marked(m);
    for (ll i = 0, col = m - 1, col_cnt = 0; i < n * m; i++) {
      // col
      if (col_marked[col] == 0 && s[i] == '1') {
        col_cnt += 1, col_marked[col] = 1;
      }
      col = (col - 1 + m) % m;
      // row
      if (i < m) {
        row_cnt[i] = (pre[i + 1] > 0);
      } else {
        // [i-m+1, i]
        row_cnt[i] = row_cnt[i - m] + ((pre[i + 1] - pre[i - m + 1]) > 0);
      }
      cout << col_cnt + row_cnt[i] << " ";
    }
    cout << "\n";
  }
}
