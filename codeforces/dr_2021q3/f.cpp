#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
using Info = tuple<ll, ll, ll>;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, res = 0, cur = 0;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<Info> maxi, mini;                            // [v, l, r],  [left, right)
  vector<vector<Info>> maxi_info(61), mini_info(61);  // [cnt, l, r]
  auto cnt = [&](ll x) { return __builtin_popcountll(x); };
  auto get_last = [&](vector<Info>& info) { return info.size() ? get<0>(info.back()) : 0ll; };
  auto _query = [&](vector<Info>& info, ll t) {
    // the number equals to bits in [0, t)
    auto it = upper_bound(info.begin(), info.end(), t, [](ll x, Info& y) { return x < get<2>(y); });
    if (it == info.end()) return get_last(info);
    auto [sum, l, r] = *it;
    return sum - (r - max(t, l));
  };
  auto query = [&](vector<Info>& info, ll l, ll r) { return _query(info, r) - _query(info, l); };
  for (int i = 0; i < n; i++) {
    int bits = cnt(a[i]);
    ll pre = i;
    while (maxi.size() && get<0>(maxi.back()) < a[i]) {
      auto [v, l, r] = maxi.back();
      pre = l;
      cur -= query(mini_info[cnt(v)], l, r);
      maxi_info[cnt(v)].pop_back(), maxi.pop_back();
    }
    ll pre_sum = get_last(maxi_info[bits]) + i + 1 - pre;
    maxi_info[bits].push_back({pre_sum, pre, i + 1});
    maxi.push_back({a[i], pre, i + 1});
    cur += query(mini_info[bits], pre, i + 1);

    pre = i;
    while (mini.size() && get<0>(mini.back()) > a[i]) {
      auto [v, l, r] = mini.back();
      pre = l;
      cur -= query(maxi_info[cnt(v)], l, r);
      mini_info[cnt(v)].pop_back(), mini.pop_back();
    }
    pre_sum = get_last(mini_info[bits]) + i + 1 - pre;
    mini_info[bits].push_back({pre_sum, pre, i + 1});
    mini.push_back({a[i], pre, i + 1});
    cur += query(maxi_info[bits], pre, i + 1);

    res += cur;
  }
  cout << res << '\n';
}
