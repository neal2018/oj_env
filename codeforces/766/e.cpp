#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto f = [&]() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<tuple<ll, ll, ll, ll, ll>> ladder(k);
    set<ll> layer;
    map<ll, vector<pair<ll, ll>>> go;
    for (int i = 0; i < k; i++) {
      auto& [aa, b, c, d, e] = ladder[i];
      cin >> aa >> b >> c >> d >> e, aa--, b--, c--, d--;
      layer.insert(aa);
      layer.insert(c);
      go[aa].push_back({b, i});
    }
    layer.insert(0);
    layer.insert(n - 1);
    map<ll, vector<pair<ll, ll>>> reached;
    reached[0].push_back({0, 0});
    for (auto& h : layer) {
      if (h == n - 1) {
        ll maxi = -inf;
        if (!reached[h].size()) {
          cout << "NO ESCAPE\n";
          return;
        }
        for (auto& [p, v] : reached[h]) maxi = max(maxi, v - abs(m - 1 - p) * a[h]);
        cout << -maxi << '\n';
        return;
      }
      sort(go[h].begin(), go[h].end());
      sort(reached[h].begin(), reached[h].end());
      multiset<ll> left, right;
      for (auto& [p, v] : reached[h]) right.insert(v - a[h] * p);
      if (!reached[h].size()) continue;
      ll e = 0, sz = reached[h].size();
      for (auto& [t, id] : go[h]) {
        while (e < sz && reached[h][e].first <= t) {
          auto& [p, v] = reached[h][e];
          right.erase(right.find(v - a[h] * p));
          left.insert(v + a[h] * p);
          e++;
        }
        ll maxi = -inf;
        if (right.size()) maxi = max(maxi, (*right.rbegin()) + a[h] * t);
        if (left.size()) maxi = max(maxi, (*left.rbegin()) - a[h] * t);
        auto& [aa, b, c, d, ee] = ladder[id];
        reached[c].push_back({d, maxi + ee});
      }
    }
  };
  while (T--) f();
}
