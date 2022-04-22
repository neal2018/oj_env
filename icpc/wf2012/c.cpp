#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;

const auto PI = acos(-1);
constexpr ld eps = 1e-12;
const int MX = 101;
const int MXLEN = 5e5;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);

  auto mmin = [&](int x, int y) {
    if(x == -1) return y;
    if(y == -1) return x;
    return min(x, y);
  };

  ll T = 1, n;
  while (cin >> n) {
    cout << "Case " << T << ": ";

    int ts = n - 2;
    auto complement = [&](int mask) {
      int res = 0;
      for(int i = 1; i <= ts; i++) {
        if(!(mask & (1 << i))) res |= (1 << i);
      }
      return res;
    };

    int m;
    cin >> m;
    vector<vector<int>> dist(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      dist[u][v] = mmin(dist[u][v], w);
      dist[v][u] = mmin(dist[v][u], w);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          if(dist[j][i] != -1 && dist[i][k] != -1) 
            dist[j][k] = mmin(dist[j][k], dist[j][i] + dist[i][k]);
        }
      }
    }
    if(n == 3) {
      cout << 2 * (dist[0][1] + dist[1][2]) << '\n';
      T++;
      continue;
    }
    vector<vector<int>> dp1(n, vector<int>(1 << n, -1));
    vector<vector<int>> dp2(n, vector<int>(1 << n, -1));
    for(int i = 1; i <= ts; i++) {
      dp1[i][1 << i] = dist[0][i];
      dp2[i][1 << i] = dist[n - 1][i];
    }
    for(int i = 1; i < ts; i++) {
      for(int mask = 0; mask < (1 << n); mask++) {
        if(mask & 1 || mask & (1 << (n - 1))) continue;
        if(__builtin_popcount(mask) != i) continue;
        for(int j = 1; j <= ts; j++) {
          for(int k = 1; k <= ts; k++) {
            if(!(mask & (1 << j)) || (mask & (1 << k))) continue;
            dp1[k][mask | (1 << k)] = mmin(dp1[k][mask | (1 << k)], dp1[j][mask] + dist[j][k]);
            dp2[k][mask | (1 << k)] = mmin(dp2[k][mask | (1 << k)], dp2[j][mask] + dist[j][k]);
          }
        }
      }
    }
    int fl = ts/2, ce = (ts + 1)/2;
    vector<int> save(1 << n, -1);
    for(int mask = 0; mask < (1 << n); mask++) {
      if(mask & 1 || mask & (1 << (n - 1))) continue;
      int bitct = __builtin_popcount(mask);
      if(bitct != fl && bitct != ce) continue;
      int cmask = complement(mask);
      for(int end = 1; end <= ts; end++) {
        for(int end2 = 1; end2 <= ts; end2++) {
          if(!(mask & (1 << end)) || !(cmask & (1 << end2))) continue;
          save[mask] = mmin(save[mask], dp1[end][mask] + dp2[end2][cmask] + dist[end][end2]);
        }
      }
    }

    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << n); mask++) {
      if(mask & 1 || mask & (1 << (n - 1))) continue;
      if(__builtin_popcount(mask) != fl) continue;
      int cmask = complement(mask);
      ans = min(ans, save[mask] + save[cmask]);
    }
    cout << ans << '\n';
    T++;
  }
}
