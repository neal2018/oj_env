#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

int mmin(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return min(a, b);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> mat(26, vector<int>(26, -1));
  FOR(i, n) {
    char u, v;
    cin >> u >> v;
    int w;
    cin >> w;
    mat[u - 'a'][v - 'a'] = w;
  }

  vector<vector<pii>> adj(26);
  FOR(i, 26) FOR(j, 26) {
    if (mat[i][j] == -1 || mat[j][i] == -1) continue;
    adj[i].push_back({j, mat[i][j] + mat[j][i]});
    adj[j].push_back({i, mat[i][j] + mat[j][i]});
  }

  int l = (k - 1) / 2;
  vector<vector<int>> dp(l + 1, vector<int>(26, -1));
  FOR(i, 26) dp[0][i] = 0;
  FOR(i, l) {
    FOR(j, 26) {
      for (auto [v, w] : adj[j]) {
        dp[i + 1][v] = mmin(dp[i + 1][v], dp[i][j] + w);
      }
    }
  }

  int ans = -1;
  FOR(i, 26) {
    if (k & 1) {
      ans = mmin(ans, dp[l][i]);
    } else {
      if (mat[i][i] == -1) continue;
      ans = mmin(ans, dp[l][i] + mat[i][i]);
    }
  }
  cout << ans << '\n';
}