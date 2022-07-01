#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto& x : a) cin >> x;
    if (a[0][0] == '*') {
      cout << "-1\n";
      continue;
    }
    vector dist(n, vector(n, vector(4, vector<int>(m + 1, inf))));
    vector<pair<int, int>> d4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto i : {0, 1, 2, 3}) dist[0][0][i][0] = 0;
    vector<array<int, 5>> q{{0, 0, 0, 0, 0}}, nq;
    int res = inf;
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& [i, j, cost, d, streak] : q) {
        if (i == n - 1 && j == n - 1) res = min(res, cost);
        if (cost > dist[i][j][d][streak]) continue;
        for (int nd = 0; nd < 4; nd++) {
          auto& [di, dj] = d4[nd];
          int ii = i + di, jj = j + dj;
          if (0 <= ii && ii < n && 0 <= jj && jj < n && a[ii][jj] != '*') {
            int nex_streak = nd == d ? streak + 1 : 1;
            if (nex_streak <= m && cost + 1 < dist[ii][jj][nd][nex_streak]) {
              dist[ii][jj][nd][nex_streak] = cost + 1;
              nq.push_back({ii, jj, cost + 1, nd, nex_streak});
            }
          }
        }
      }
    }
    cout << (res == inf ? -1 : res) << "\n";
  }
}
