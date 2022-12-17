#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, c, d;
    cin >> n >> c >> d;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater());
    auto check = [&](ll mid) {
      ll gain = accumulate(a.begin(), a.begin() + min(mid + 1, n), 0ll);
      ll full = d / (mid + 1);
      ll remain = d % (mid + 1);
      ll remain_gain = accumulate(a.begin(), a.begin() + min(remain, n), 0ll);
      ll total = full * gain + remain_gain;
      return total >= c;
    };
    if (!check(0)) {
      cout << "Impossible\n";
      continue;
    }
    if (check(d + 1)) {
      cout << "Infinity\n";
      continue;
    }
    ll l = 0, r = d + 1;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << "\n";
  }
}
