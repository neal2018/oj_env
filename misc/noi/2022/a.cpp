#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n, q;
  cin >> n >> q;
  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  vector<deque<int>> a(n);
  vector<map<int, int>> freq(n);
  for (int i = 0; auto& dq : a) {
    int cnt;
    cin >> cnt;
    dq.resize(cnt);
    for (auto& x : dq) {
      cin >> x;
      freq[i][x]++;
    }
    i++;
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y, x--, x = o[x];
      a[x].push_back(y);
      freq[x][y]++;
    } else if (t == 2) {
      int x;
      cin >> x, x--, x = o[x];
      const auto last = a[x].back();
      freq[x][last]--;
      a[x].pop_back();
    } else if (t == 3) {
      int m;
      cin >> m;
      vector<int> xs(m);
      for (auto& x : xs) cin >> x, x--, x = o[x];
      vector<ll> pre(m + 1);
      for (int i = 0; i < m; i++) pre[i + 1] = pre[i] + a[xs[i]].size();
      [&] {
        for (int tries = 20; tries > 0; tries--) {
          const auto pos = rng() % pre.back();
          const auto a_id = (upper_bound(pre.begin(), pre.end(), pos) - pre.begin()) - 1;
          const auto e_id = pos - pre[a_id];
          const auto v = a[xs[a_id]][e_id];
          ll cnt = 0;
          for (const auto& x : xs) {
            const auto it = freq[x].find(v);
            if (it != freq[x].end()) cnt += it->second;
          }
          if (cnt * 2 > pre.back()) {
            cout << v << "\n";
            return;
          }
        }
        cout << "-1\n";
      }();
    } else {
      int x1, x2, x3;
      cin >> x1 >> x2 >> x3, x1--, x2--, x3--, x1 = o[x1], x2 = o[x2];
      while (o.size() <= x3) o.push_back(0);
      if (a[x1].size() < a[x2].size()) {
        o[x3] = x2;
        for (const auto& x : a[x1]) {
          a[x2].push_front(x);
          freq[x2][x]++;
        }
      } else {
        o[x3] = x1;
        for (const auto& x : a[x2]) {
          a[x1].push_back(x);
          freq[x1][x]++;
        }
      }
    }
  }
}
