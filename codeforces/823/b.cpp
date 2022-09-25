#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

constexpr ld eps = 1e-7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for (auto& x : a) cin >> x;
    for (auto& x : t) cin >> x;
    ld res = 0;
    auto check = [&](ld mid) {
      vector<pair<ld, ld>> inter;
      inter.reserve(n);
      for (int i = 0; i < n; i++) {
        ld dist = max(ld(0), (mid - t[i]));
        inter.push_back({a[i] - dist, a[i] + dist});
      }
      sort(inter.begin(), inter.end());
      vector<pair<ld, ld>> remain;
      for (auto& [l, r] : inter) {
        if (remain.size() == 0) {
          remain.push_back({l, r});
        } else if (remain.back().second >= l) {
          pair<ld, ld> nex = {max(remain.back().first, l), min(remain.back().second, r)};
          remain.back() = nex;
        } else {
          return false;
        }
      }
      res = remain[0].first;
      return true;
    };
    ld l = 0;
    ld r = *max_element(a.begin(), a.end()) + *max_element(t.begin(), t.end());
    for (; (r - l) > eps;) {
      ld mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }
    check(l);
    cout << res << "\n";
  }
}
