#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  n = int(a.size());
  unordered_set<ll> has;
  set<pair<ll, array<int, 10>>> st;
  set<array<int, 10>> seen;
  for (int i = 0; i < n; i++) {
    array<int, 10> dist{};
    dist[i] = 1;
    seen.insert(dist);
    st.insert({a[i], dist});
  }
  while (true) {
    auto [val, dist] = *st.begin();
    st.erase(st.begin());
    if (has.count(val)) continue;
    has.insert(val);
    if (has.size() == k) {
      cout << val;
      return 0;
    }
    for (int i = 0; i < n; i++) {
      auto t = dist;
      t[i]++;
      if (seen.count(t) == 0) {
        seen.insert(t);
        st.insert({val + a[i], t});
      }
    }
  }
}
