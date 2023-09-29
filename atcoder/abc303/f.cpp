#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, h;
  cin >> n >> h;
  vector<array<ll, 2>> a(n);
  for (auto& [t, d] : a) cin >> t >> d;

  sort(a.rbegin(), a.rend());

  auto check = [&](ll mid) {
    priority_queue<ll> st;
    vector<array<ll, 2>> ts;
    ll maxi = 0;
    for (int i = 0; i < n; i++) {
      auto [t, d] = a[i];
      auto time = mid - t + 1;
      if (time <= 0) {
        maxi = max(maxi, d);
      } else {
        st.push(t * d);
        ts.push_back({time, i});
      }
    }
    __int128 damage = 0;
    ll prev = 0;
    priority_queue<ll> to_rm;
    ts.push_back({mid, -1});
    for (int i = 0, j = 0; i < ts.size(); i = j) {
      for (j = i; j < ts.size() && ts[j][0] == ts[i][0];) j++;
      auto time = ts[i][0];
      // best in [prev, time)
      while (st.size() && to_rm.size() && st.top() == to_rm.top()) {
        st.pop(), to_rm.pop();
      }
      __int128 length = (time - prev);
      auto best_single = st.size() ? st.top() : 0;
      auto best = best_single * length;
      auto multiplier = (mid - prev + mid - prev - length + 1) * length / 2;
      auto alt = maxi * multiplier;

      if (maxi && maxi * (mid - prev - length + 1) < best_single) {
        // maxi * (mid - prev - length2 + 1) >= best_single
        auto length2 = mid - prev - (best_single + maxi - 1) / maxi + 1;
        if (length2 < 0) length2 = 0;
        auto multiplier2 = (mid - prev + mid - prev - length2 + 1) * length2 / 2;
        alt = maxi * multiplier2 + best_single * (length - length2);
      }

      damage += max(best, alt);
      if (damage >= h) return true;
      if (time >= mid) break;
      for (int k = i; k < j; k++) {
        auto [t, d] = a[ts[k][1]];
        maxi = max(maxi, d);
        to_rm.push(t * d);
      }
      prev = time;
    }
    return damage >= h;
  };
  check(8);

  ll maxi = 0;
  for (auto& [t, d] : a) maxi = max(maxi, d);
  ll l = 1, r = (h + maxi - 1) / maxi + 1;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << r << "\n";
}
