#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> bad(n);
  for (int i = 1; i < n - 1; i++) {
    bad[i] = a[i - 1] >= a[i] && a[i] >= a[i + 1];
  }
  vector<int> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + bad[i];
  while (q--) {
    int l, r;
    cin >> l >> r, l--;
    ll res = pre[r] - pre[l];
    res -= bad[l];
    if (r - 1 > l) res -= bad[r - 1];
    cout << (r - l) - res << "\n";
  }
}
