#include <bits/stdc++.h>
using namespace std;
#define double long double
#define FOR(x, n) for (int x = 0; x < n; x++)
// #define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  // const double PI = acos(-1);
  int n;
  ll k;
  cin >> n >> k;
  const double PI = acos(-1);
  auto mul = [&](const vector<double>& aa, const vector<double>& bb) {
    int n = (int)aa.size(), m = (int)bb.size(), bit = 1;
    while ((1 << bit) < n + m - 1) bit++;
    int len = 1 << bit;
    vector<complex<double>> a(len), b(len);
    vector<int> rev(len);
    for (int i = 0; i < n; i++) a[i].real(aa[i]);
    for (int i = 0; i < m; i++) b[i].real(bb[i]);
    for (int i = 0; i < len; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    auto fft = [&](vector<complex<double>>& p, int inv) {
      for (int i = 0; i < len; i++)
        if (i < rev[i]) swap(p[i], p[rev[i]]);
      for (int mid = 1; mid < len; mid *= 2) {
        auto w1 = complex<double>(cos(PI / mid), (inv ? -1 : 1) * sin(PI / mid));
        for (int i = 0; i < len; i += mid * 2) {
          auto wk = complex<double>(1, 0);
          for (int j = 0; j < mid; j++, wk = wk * w1) {
            auto x = p[i + j], y = wk * p[i + j + mid];
            p[i + j] = x + y, p[i + j + mid] = x - y;
          }
        }
      }
      if (inv == 1) {
        for (int i = 0; i < len; i++) p[i].real(p[i].real() / len);
      }
    };
    fft(a, 0), fft(b, 0);
    for (int i = 0; i < len; i++) a[i] = a[i] * b[i];
    fft(a, 1);
    a.resize(n + m - 1);
    vector<double> res(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) res[i] = a[i].real();
    return res;
  };
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<vector<double>> dp(n, vector<double>{1});
  vector<int> mark(n + 1);
  function<void(int, int)> dfs = [&](int node, int fa) {
    for (auto& ne : g[node]) {
      if (ne == fa) continue;
      dfs(ne, node);
      dp[node] = mul(dp[node], dp[ne]);
      for (int i = 1; i < dp[node].size(); i++) {
        if (dp[node][i] >= 2 * k) mark[i] = 1;
        dp[node][i] = (__int128)(dp[node][i] + 0.49);
      }
    }
    // cout << "node=" << node << " " << fa << "\n";
    // for (auto& x : dp[node]) {
    //   cout << x << " ";
    // }
    // cout << "\n";
    dp[node].insert(dp[node].begin(), 1);
    for (int i = 1; i < dp[node].size(); i++) {
      if (dp[node][i] >= 2 * k) mark[i] = 1;
      dp[node][i] = (__int128)(dp[node][i] + 0.49);
    }
  };
  dfs(0, -1);
  vector<__int128> sum(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < dp[i].size(); j++) {
      sum[j] += dp[i][j];
      if (sum[j] >= 2*k) mark[j] = 1;
    }
  }
  // for (auto& x : dp) {
  //   for (auto& xx : x) cout << xx << " ";
  //   cout << "\n";
  // }
  // for (auto& x : sum) cout << x << " ";
  // cout << "\n";
  __int128 cur = 0;
  for (int i = 1; i < n + 1; i++) {
    cur += sum[i];
    if (mark[i] || cur >= k) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << "-1\n";
}