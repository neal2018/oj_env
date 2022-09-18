#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, k, len, d;
    cin >> n >> k >> len >> d;
    vector<vector<array<int, 2>>> events(d + 1);
    int m;
    cin >> m;
    while (m--) {
      int i, l, r;
      cin >> i >> l >> r, i--;
      events[l].push_back({1, i});
      events[r].push_back({-1, i});
    }
    vector<ll> cnt(n);
    multiset<ll> small, large;
    for (int i = 0; i < k; i++) small.insert(0);
    for (int i = k; i < n; i++) large.insert(0);
    ll sum = 0, res = 1e18;
    auto add = [&](int is_in, int id) {
      if (small.find(cnt[id]) != small.end()) {
        small.extract(cnt[id]);
        sum -= cnt[id];

        large.insert(cnt[id] + is_in);
        auto t = *large.begin();
        sum += t;
        large.extract(t);
        small.insert(t);
      } else {
        large.extract(cnt[id]);

        small.insert(cnt[id] + is_in);
        sum += cnt[id] + is_in;
        auto t = *small.rbegin();
        sum -= t;
        small.extract(t);
        large.insert(t);
      }
      cnt[id] += is_in;
    };
    for (int i = 0; i <= d; i++) {
      if (i >= len) {
        for (auto& [is_in, id] : events[i - len]) {
          if (is_in == -1) add(is_in, id);
        }
        res = min(res, sum);
      }
      for (auto& [is_in, id] : events[i]) {
        if (is_in == 1) add(is_in, id);
      }
    }
    cout << res << "\n";
  }
}
