#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, t;
  string s;
  cin >> n >> t >> s;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<array<ll, 3>> inter;  // time, is_end(-1:end), type(0:B, 1:R)
  for (int i = 0; i < n; i++) {
    inter.push_back({a[i], 1, s[i] == 'R'});
    inter.push_back({a[i] + t, -1, s[i] == 'R'});
  }
  sort(inter.begin(), inter.end());
  ll res = 0, pre = inter[0][0], ni = inter.size();
  array<ll, 2> cnt = {};  // blue, red
  for (int i = 0, j; i < ni; i = j) {
    for (j = i; j < ni && inter[j][0] == inter[i][0];) j++;
    if (cnt[0] > 0 && cnt[1] == 0) {
      res += inter[i][0] - pre;
    }
    pre = inter[i][0];
    for (int k = i; k < j; k++) {
      auto& [time, is_end, type] = inter[k];
      cnt[type] += is_end;
    }
  }
  cout << res << "\n";
}
