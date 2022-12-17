#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> pre(n + 1);
  vector<ll> sum(n + 1);
  vector<map<int, vector<int>>> mp(2);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] ^ a[i];
    mp[i % 2][pre[i + 1]].push_back(i);
    sum[i + 1] = sum[i] + a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r, l--;
    if ((pre[r] ^ pre[l]) != 0) {
      cout << "-1\n";
      continue;
    }
    if (sum[r] == sum[l]) {
      cout << "0\n";
      continue;
    }
    if (r - l == 2) {
      cout << "-1\n";
      continue;
    }
    if ((r - l) % 2 == 1) {
      cout << "1\n";
      continue;
    }
    if (a[l] == 0 || a[r - 1] == 0) {
      cout << "1\n";
      continue;
    }
    auto& v = mp[(l % 2)][pre[l]];
    auto it = lower_bound(v.begin(), v.end(), l);
    if (it != v.end() && *it < r) {
      cout << "2\n";
    } else {
      cout << "-1\n";
    }
  }
}
