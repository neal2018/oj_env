#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SIZE = 30;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> poss(n, (1 << SIZE) - 1);
  vector<int> a(n, -1);
  vector<vector<array<int, 3>>> req(n);
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    if (l > r) swap(l, r);
    poss[l] &= x, poss[r] &= x;
    if (l == r) {
      a[l] = x;
    } else {
      req[l].push_back({l, r, x});
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) {
      int need = 0;
      for (auto& [l, r, x] : req[i]) {
        if (l == -1) {
          need |= x;
        } else {
          int cur = x & (~poss[r]);
          need |= cur;
        }
      }
      a[i] = need;
    }
    for (auto& [l, r, x] : req[i]) {
      if (l != -1) {
        int cur = x & (~a[i]);
        req[r].push_back({-1, -1, cur});
      }
    }
  }
  for (auto& x : a) cout << x << " ";
  cout << "\n";
}
