#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<array<int, 2>> down;
  for (int i = 0, j = 0; i < n;) {
    if (i == n - 1) break;
    if (a[i] < a[i + 1]) {
      for (j = i + 1; j < n && a[j - 1] < a[j];) j++;
      i = j - 1;
    } else {
      for (j = i + 1; j < n && a[j - 1] >= a[j];) j++;
      down.push_back({i, j});
      i = j;
    }
  }
  vector<int> pre(down.size() + 1);
  for (int i = 0; i < down.size(); i++) {
    auto [l, r] = down[i];
    pre[i + 1] = pre[i] + (r - l) - 2;
  }
  while (q--) {
    int l, r;
    cin >> l >> r, l--;
    int left = int(upper_bound(down.begin(), down.end(), array{l, l}) - down.begin());
    if (left > 0) left--;
    int right = int(upper_bound(down.begin(), down.end(), array{r, n}) - down.begin());
    ll res = pre[right] - pre[left];
    auto adjust = [&](int i) {
      if (i < left || i >= right) return;
      auto [x, y] = down[i];
      res -= (y - x) - 2;
      x = max(x, l), y = min(y, r);
      res += max(0, (y - x) - 2);
    };
    adjust(left);
    if (right - 1 != left) adjust(right - 1);
    cout << (r - l) - res << "\n";
  }
}
