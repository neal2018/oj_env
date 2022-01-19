#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 998244353;
constexpr int SZ = 10, MAXN = 2e6 + 10;
pair<int, int> mp[MAXN];
int parent[MAXN], length[MAXN], e[MAXN][SZ];
struct GSAM {
  int total = 1;
  void init(int n) {
    memset(parent, 0, n * 4);
    memset(length, 0, n * 4);
    memset(e, 0, n * 4 * SZ);
    parent[0] = -1;
  }
  int extend(int c, int p) {
    int r = 0, f = 1;
    if (!e[p][c]) {
      length[total] = length[p] + 1;
      f = 0, r = total++;
      for (; ~p && !e[p][c]; p = parent[p]) e[p][c] = r;
    }
    if (f || ~p) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        if (f) return q;
        parent[r] = q;
      } else {
        parent[total] = parent[q], length[total] = length[p] + 1;
        for (int i = 0; i < SZ; i++) e[total][i] = e[q][i];
        int qq = parent[q] = total++;
        mp[qq] = mp[q];
        for (; ~p && e[p][c] == q; p = parent[p]) e[p][c] = qq;
        if (f) return qq;
        parent[r] = qq;
      }
    }
    return r;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  GSAM sam;
  while (T--) {
    int n, m;
    cin >> n >> m;
    string t, temp;
    sam.init(n * m * 2 + 10);
    int p = 0;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      for (int j = 0; j < m; j++) {
        p = sam.extend(temp[j] - '0', p);
        if (j >= 1) mp[p] = {i, j};
        if (j >= 2) mp[p] = {i, j};
      }
      p = 0;
    }
    cin >> t;
    vector<int> dp(m + 1, 0);
    vector<pair<int, int>> save2(m + 1), save3(m + 1);
    dp[0] = 1;
    int rolling = 0;
    for (int i = 0; i < m; i++) {
      int c = t[i] - '0', f = 0;
      for (; p != -1 && e[p][c] == 0; p = parent[p], f = 1) {
      }
      if (p == -1) break;
      f ? rolling = (length[p] + 1) : rolling++;
      p = e[p][c];
      if (rolling >= 2 && i >= 1) dp[i + 1] |= dp[i - 1], save2[i + 1] = mp[p];
      if (rolling >= 3 && i >= 2) dp[i + 1] |= dp[i - 2], save3[i + 1] = mp[p];
    }
    if (!dp[m]) {
      cout << "-1\n";
    } else {
      vector<tuple<int, int, int>> res;
      res.reserve(m / 2);
      for (int i = m; i > 0;) {
        if (i >= 2 && dp[i - 2] && save2[i] != pair{0, 0}) {
          auto& [x, y] = save2[i];
          res.emplace_back(x, y - 1, y);
          i -= 2;
        } else {
          auto& [x, y] = save3[i];
          res.emplace_back(x, y - 2, y);
          i -= 3;
        }
      }
      reverse(res.begin(), res.end());
      cout << res.size() << "\n";
      for (auto& [x, y, z] : res) cout << y + 1 << " " << z + 1 << " " << x + 1 << "\n";
    }
  }
}
