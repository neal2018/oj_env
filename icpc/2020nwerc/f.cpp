#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<array<ll, 2>> a(n);
  set<ll> survivor;
  for (int i = 0; auto& [x, y] : a) cin >> x >> y, survivor.insert(i++);
  sort(a.begin(), a.end());
  set<tuple<ld, ll, ll>> events;
  auto add = [&](int i, int j) {
    auto [x1, v1] = a[i];
    auto [x2, v2] = a[j];
    if (v1 != v2 && (x2 - x1) * (v1 - v2) >= 0) {
      ld t = ld(x2 - x1) / (v1 - v2);
      events.insert({t, i, j});
    }
  };
  for (int i = 1; i < n; i++) {
    // x1 + tv1 = x2 + tv2
    // t = (x2-x1)/(v1-v2)
    add(i - 1, i);
  }
  while (events.size()) {
    auto [t, id1, id2] = *events.begin();
    events.erase(events.begin());
    if (survivor.count(id1) == 0 || survivor.count(id2) == 0) continue;
    auto it1 = survivor.lower_bound(id1);
    if (it1 != survivor.begin()) {
      it1--;
      auto it2 = survivor.upper_bound(id2);
      if (it2 != survivor.end()) {
        add(*it1, *it2);
      }
    }
    survivor.erase(id1);
    survivor.erase(id2);
  }
  cout << survivor.size() << "\n";
  for (auto& x : survivor) cout << x + 1 << " ";
}
