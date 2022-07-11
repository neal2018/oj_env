#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

struct SegTree {
  ll n;
  vector<ll> t;
  SegTree(ll _n) : n(_n), t(2 * n, inf) {}
  SegTree() : n(0), t(0, inf) {}
  void modify(ll p, ll v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = min(t[2 * p], t[2 * p + 1]);
  }
  ll query(ll l, ll r) {
    ll res = inf;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = min(res, t[l++]);
      if (r & 1) res = min(res, t[--r]);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, m;
    cin >> n;
    vector<int> s;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (s.size() == 0 || x != s.back()) s.push_back(x);
    }
    n = int(s.size());
    cin >> m;
    map<int, vector<int>> mp;
    for (int i = 0, x; i < m; i++) {
      cin >> x;
      mp[x].push_back(i);
    }
    if (n == 1) {
      cout << "0\n";
      continue;
    }

    for (auto& [k, v] : mp) sort(v.begin(), v.end());
    map<int, array<SegTree, 2>> segs;
    for (auto& [k, v] : mp) {
      int len = int(v.size());
      segs[k] = {SegTree(len), SegTree(len)};
    }

    // dp[i][j]
    vector<vector<ll>> dp(n, vector<ll>(m, inf));
    {
      int i = n - 1;
      for (int j_id = 0; j_id < mp[s[i]].size(); j_id++) {
        ll j = mp[s[i]][j_id];
        dp[i][j] = 0;
        segs[s[i]][0].modify(j_id, dp[i][j] + j);
        segs[s[i]][1].modify(j_id, dp[i][j] - j);
      }
    }

    ll res = inf;
    for (int i = n - 2; i >= 0; i--) {
      for (int j_id = 0; j_id < mp[s[i]].size(); j_id++) {
        ll j = mp[s[i]][j_id];
        auto& v = mp[s[i + 1]];
        // dp[i][j] = min(dp[i][j], dp[i + 1][n_j] + abs(j - n_j));
        auto it = int(lower_bound(v.begin(), v.end(), j) - v.begin());
        // j  < n_j
        dp[i][j] = min(dp[i][j], segs[s[i + 1]][0].query(it, v.size()) - j);
        dp[i][j] = min(dp[i][j], segs[s[i + 1]][1].query(0, it) + j);

        if (i == 0) {
          res = min(res, dp[i][j]);
        }

        segs[s[i]][0].modify(j_id, dp[i][j] + j);
        segs[s[i]][1].modify(j_id, dp[i][j] - j);
      }
    }
    cout << res << "\n";
  }
}
