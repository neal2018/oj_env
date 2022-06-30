#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  array<int, 2> k;
  array<vector<int>, 2> a;
  for (int j : {0, 1}) {
    cin >> k[j];
    a[j] = vector<int>(k[j]);
    for (auto& x : a[j]) cin >> x;
  }
  array<vector<int>, 2> dp{vector<int>(n, -1), vector<int>(n, -1)};
  // starts at i, j first. 1:win, 0:lose, -1:loop
  array<vector<int>, 2> deg{vector<int>(n, int(a[0].size())), vector<int>(n, int(a[1].size()))};

  vector<int> q{0, n}, nq;
  dp[0][0] = dp[1][0] = 0;
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      int i = node / n, j = node % n;
      for (auto& x : a[!i]) {
        int nex = (j - x + n) % n;
        if (dp[!i][nex] != -1) continue;
        if (dp[i][j] == 0) {
          dp[!i][nex] = 1;
          nq.push_back((!i) * n + nex);
        } else if (--deg[!i][nex] == 0) {
          dp[!i][nex] = 0;
          nq.push_back((!i) * n + nex);
        }
      }
    }
  }

  for (auto i : {0, 1}) {
    for (int j : views::iota(1, n)) {
      cout << (dp[i][j] == 1 ? "Win" : (dp[i][j] == 0 ? "Lose" : "Loop")) << " ";
    }
    cout << "\n";
  }
}
