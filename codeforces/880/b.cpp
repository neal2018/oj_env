#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  if (k > n) {
    cout << m + 1 << " 0\n";
    return 0;
  }
  auto get_left = [&](ll i, ll cur) -> ll {
    if (i < 0) return 0;
    if (i >= n) return m;
    return (a[i] + 1 + cur + 1) / 2;
  };
  auto get_right = [&](ll i, ll cur) -> ll {
    if (i < 0) return 0;
    if (i >= n) return m;
    return (a[i] - 1 + cur) / 2;
  };
  sort(a.begin(), a.end());
  ll res = 0;
  ll res_cnt = 0;

  if (a[0] != 0) {
    const auto cnt = get_right(k - 1, 0);
    if (cnt > res_cnt) res_cnt = cnt, res = 0;
  }
  const auto all = set(a.begin(), a.end());
  for (int i = 0, j = 0; i < n; i = j) {
    for (j = i; j < n && a[i] == a[j];) j++;
    const auto pos_cnt = j - i;
    if (pos_cnt < k) {
      const auto cur = a[i];
      const auto left_cnt = get_left(j - k, cur);
      const auto right_cnt = get_right(i + k - 1, cur);
      const auto cnt = right_cnt - left_cnt + 1;
      if (cnt > res_cnt || (cnt == res_cnt && cur < res)) res_cnt = cnt, res = cur;
    }
    auto f = [&](ll cur) {
      const auto left_cnt = get_left(j - k, cur);
      const auto right_cnt = get_right(j + k - 1, cur);
      const auto cnt = right_cnt - left_cnt + 1;
      if (cnt > res_cnt || (cnt == res_cnt && cur < res)) res_cnt = cnt, res = cur;
    };
    if (a[i] + 1 <= m && all.count(a[i] + 1) == 0) {
      f(a[i] + 1);
      if (a[i] + 2 <= m && all.count(a[i] + 2) == 0) {
        f(a[i] + 2);
      }
    }
    auto g = [&](ll cur) {
      const auto left_cnt = get_left(i - k, cur);
      const auto right_cnt = get_right(i + k - 1, cur);
      const auto cnt = right_cnt - left_cnt + 1;
      if (cnt > res_cnt || (cnt == res_cnt && cur < res)) res_cnt = cnt, res = cur;
    };
    if (a[i] - 1 >= 0 && all.count(a[i] - 1) == 0) {
      g(a[i] - 1);
      if (a[i] - 2 >= 0 && all.count(a[i] - 2) == 0) {
        g(a[i] - 2);
      }
    }
  }

  cout << res_cnt << " " << res << "\n";
}
