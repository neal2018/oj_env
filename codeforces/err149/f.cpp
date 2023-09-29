#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Set {
  ll limit;
  ll sum = 0, cnt = 0;
  priority_queue<ll> first{};
  priority_queue<ll> second{};
  void insert(ll x) {
    if (second.size() == 0 || x < -second.top()) {
      first.push(x);
      sum += x, cnt++;
    } else {
      second.push(-x);
    }
    while (sum > limit) {
      auto last = first.top();
      first.pop();
      second.push(-last);
      sum -= last, cnt--;
    }
  };
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    auto check = [&](ll mid) {
      const auto pos = [&] {
        vector<ll> cnt(n);
        auto store = Set{mid};
        for (int i = 0; i < n; i++) {
          store.insert(a[i]);
          cnt[i] = store.cnt;
        }
        return cnt;
      }();
      const auto neg = [&] {
        vector<ll> cnt(n);
        auto store = Set{mid};
        for (int i = n - 1; i >= 0; i--) {
          store.insert(a[i]);
          cnt[i] = store.cnt;
        }
        return cnt;
      }();
      ll maxi = max(pos.back(), neg[0]);
      for (int i = 0; i < n - 1; i++) {
        maxi = max(maxi, pos[i] + neg[i + 1]);
      }
      return maxi >= k;
    };

    auto b = a;
    sort(b.begin(), b.end());
    ll l = 0, r = accumulate(b.begin(), b.begin() + k, 0ll);
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
}
