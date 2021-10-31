#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n + 1], b[n + 1], from[n + 1], up = n, f = 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (vector<int> q{n}, nq; q.size() && f; swap(q, nq), nq.clear()) {
    for (int x : q) {
      int d = x + b[x];
      if (d - a[d] <= 0) {
        f = 0, from[0] = x;
        break;
      }
      for (int i = min(up, d) - 1; i >= d - a[d]; i--) nq.push_back(i), from[i] = x;
      up = min(up, d - a[d]);
    }
  }
  if (f) {
    cout << -1 << '\n';
  } else {
    vector<int> res;
    for (int i = 0; i < n; i = from[i]) res.push_back(i);
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto& x : res) cout << x << ' ';
    cout << '\n';
  }
}