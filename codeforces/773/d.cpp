#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int inf = INT_MAX, res = inf;
  int n, m;
  cin >> n >> m;
  vector<pair<int, vector<int>>> a(n, {0, vector<int>(m)});
  for (auto& [w, v] : a) {
    for (auto& x : v) cin >> x;
    cin >> w;
  }
  vector<ll> compress;
  compress.reserve(n * m);
  sort(a.begin(), a.end());
  for (auto& [w, v] : a) {
    for (auto& x : v) compress.push_back(x);
  }
  sort(compress.begin(), compress.end());
  compress.erase(unique(compress.begin(), compress.end()), compress.end());
  for (auto& [w, v] : a) {
    for (auto& x : v) x = int(lower_bound(compress.begin(), compress.end(), x) - compress.begin());
  }
  vector<ll> my_hash(compress.size());
  for (auto& x : my_hash) x = rng();
  vector<vector<pair<int, ull>>> subset(n);
  vector<ull> compress2;
  compress2.reserve(n * (1 << m));
  for (int i = 0; i < n; i++) {
    subset[i].reserve(1 << m);
    for (int mask = (1 << m) - 1; mask >= 0; mask--) {
      ull cur = 0;
      for (int j = 0; j < m; j++) {
        if (mask & (1 << j)) cur += my_hash[a[i].second[j]];
      }
      subset[i].push_back({__builtin_popcount(mask), cur});
      compress2.push_back(cur);
    }
  }
  sort(compress2.begin(), compress2.end());
  for (auto& v : subset) {
    for (auto& [sz, cur] : v) {
      cur = lower_bound(compress2.begin(), compress2.end(), cur) - compress2.begin();
    }
  }
  vector<int> st(compress2.size());
  auto add = [&](int i) {
    for (auto& [sz, cur] : subset[i]) st[cur]++;
  };
  auto remove = [&](int i) {
    for (auto& [sz, cur] : subset[i]) {
      if (st[cur] > 0) st[cur]--;
    }
  };
  auto check = [&](int i) {
    int cnt = 0;
    for (auto& [sz, cur] : subset[i]) {
      if (sz & 1) {
        cnt += st[cur];
      } else {
        cnt -= st[cur];
      }
    }
    return cnt != 0;
  };
  for (int i = 0; i < n; i++) add(i);
  int r = n - 1;
  for (int l = 0; l < r; l++) {
    // pair l and [l+1, r]
    remove(l);
    while (check(l) && r > l) {
      res = min(res, a[l].first + a[r].first);
      remove(r), r--;
    }
  }
  cout << (res == inf ? -1 : res) << "\n";
}
