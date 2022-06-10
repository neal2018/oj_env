#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MAX = 2e6 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n), has(MAX), left(MAX, -1), right(MAX, MAX);
  for (auto& x : a) cin >> x, has[x] = 1;
  for (int i : views::iota(1, MAX)) left[i] = (has[i] ? i : left[i - 1]);
  for (int i : views::iota(0, MAX - 1) | views::reverse) right[i] = (has[i] ? i : right[i + 1]);
  auto get_first = [&](ll l, ll r) {
    if (l > a.back() || r < a[0]) return -1ll;
    l = max(l, a[0]);
    return right[l] <= r ? right[l] : -1;
  };
  auto get_last = [&](ll l, ll r) {
    if (l > a.back() || r < a[0]) return -1ll;
    r = min(r, a.back());
    return left[r] >= l ? left[r] : -1;
  };
  for (ll x = 1;; x++) {
    ll lo = max(x * x - a[0], 0ll), hi = x * x + x - a[0];
    if (hi < 0) continue;
    for (ll y = x, offset = lo; a.back() + offset < y * y; y++) {
      ll start = y * y, mid = y * y + y, stop = (y + 1) * (y + 1);
      auto last = get_last(start - offset, mid - offset);
      if (last != -1) hi = min(hi, mid - last);
      auto first = get_first(mid + 1 - offset, stop - 1 - offset);
      if (first != -1) lo = max(lo, stop - first);
    }
    if (lo <= hi) {
      cout << lo << "\n";
      return 0;
    }
  }
}
