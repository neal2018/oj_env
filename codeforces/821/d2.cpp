#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, c1, c2;
    string s, s2;
    cin >> n >> c1 >> c2 >> s >> s2;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      if (s[i] != s2[i]) a.push_back(i);
    }
    if (a.size() % 2) {
      cout << "-1\n";
      continue;
    }
    if (c1 >= c2) {
      ll start = 0, res = 0, end = int(a.size());
      auto cost = [&](ll i, ll j) {
        if (i > j) swap(i, j);
        if (i + 1 == j) {
          return min(2 * c2, c1);
        } else {
          return c2;
        }
      };
      if (a.size() % 4 == 2) {
        res += cost(a[0], a.back()), start++, end--;
      }
      for (ll t = start; t + 2 < end; t += 4) {
        res += cost(a[t], a[t + 2]);
      }
      for (ll t = start + 1; t + 2 < end; t += 4) {
        res += cost(a[t], a[t + 2]);
      }
      cout << res << "\n";
    } else {
      vector<pair<int, int>> inter;
      ll res = 0;
      for (int i = 0, j; i < a.size(); i = j) {
        for (j = i + 1; j < a.size() && a[j] == a[j - 1] + 1;) j++;
        res += (j - i) / 2 * c1;
        if ((j - i) & 1) inter.push_back({i, j});
      }
      int m = int(inter.size());
      auto cost = [&](int i, int j) {
        return min((a[inter[j].first] - a[inter[i].second - 1]) * c1, c2);
      };
      vector dp(m + 1, vector<ll>(m + 1));
      for (int len = 2; len <= m; len += 2) {
        for (int l = 0; l + len <= m; l++) {
          int r = l + len;
          dp[l][r] = inf;
          dp[l][r] = min(dp[l][r], dp[l][r - 2] + cost(r - 2, r - 1));
          dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + cost(l, r - 1));
        }
      }
      for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
          cout << dp[i][j] << ' ';
        }
        cout << "\n";
      }
      cout << res + dp[0][m] << "\n";
    }
  }
}
