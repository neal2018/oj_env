#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n), legs(n);
  for (auto& x : a) cin >> x;
  for (auto& x : legs) cin >> x;
  sort(legs.begin(), legs.end());

  vector<ll> points = a;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto mid = (a[i] + a[j]) / 2;
      points.push_back(mid + 1);
      points.push_back(mid);
      points.push_back(mid - 1);
    }
  }
  vector<array<ll, 2>> res;
  for (auto& p : points) {
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int x, int y) { return abs(p - a[x]) < abs(p - a[y]); });
    vector<ll> lefts, rights;
    for (int i = 0; i < n; i++) {
      lefts.push_back(a[order[i]] - legs[i]);
      rights.push_back(a[order[i]] + legs[i]);
    }
    auto left = *max_element(lefts.begin(), lefts.end());
    auto right = *min_element(rights.begin(), rights.end());
    if (left <= right) {
      res.push_back({left, right});
    }
  }
  sort(res.begin(), res.end());
  vector<array<ll, 2>> out;
  for (auto& [l, r] : res) {
    if (out.size() == 0) {
      out.push_back({l, r});
    } else if (out.back()[1] >= l) {
      out.back()[1] = max(out.back()[1], r);
    } else {
      out.push_back({l, r});
    }
  }
  ll ans = 0;
  for (auto& [l, r] : out) ans += (r - l) + 1;
  cout << ans << "\n";
}
