#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, q;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> b(n, -1);
    vector<int> counter(2001, 0);
    vector<vector<int> > total;
    total.push_back(a);
    int cnt = 0;
    for (;; cnt++) {
      int same = 1;
      for (int i = 0; i <= 2000; i++) {
        counter[i] = 0;
      }
      for (int i = 0; i < n; i++) {
        counter[a[i]]++;
      }
      for (int i = 0; i < n; i++) {
        b[i] = counter[a[i]];
      }
      for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
          same = 0;
          break;
        }
      }
      if (same) {
        break;
      }
      swap(a, b);
      total.push_back(a);
    }
    cin >> q;
    int x, k;
    for (int i = 0; i < q; i++) {
      cin >> x >> k;
      if (k <= cnt) {
        cout << total[k][x - 1] << '\n';
      } else {
        cout << total[cnt][x - 1] << '\n';
      }
    }
  }
}