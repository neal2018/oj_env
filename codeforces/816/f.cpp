#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    auto oa = a;
    vector need(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i][j] > a[j][i]) {
          need[i][j] = 1, need[j][i] = -1;
        } else if (a[i][j] < a[j][i]) {
          need[i][j] = -1, need[j][i] = 1;
        }
      }
    }
    {
      vector<int> q, nq;
      vector<vector<int>> g(2 * n);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (need[i][j]) {
            g[i].push_back(j + n);
            g[j + n].push_back(i);
          }
        }
      }
      vector<int> deg(2 * n);
      for (int i = 0; i < 2 * n; i++) {
        deg[i] = int(g.size());
        if (g[i].size() == 1) q.push_back(i);
      }
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          for (auto& ne : g[node]) {
            {
              int row = node, col = ne;
              if (row >= n) swap(row, col);
              if (need[row][col - n] == 0) continue;
              need[row][col - n] = 0;
            }
            deg[ne]--;
            if (deg[ne] == 1) {
              nq.push_back(ne);
            }
          }
        }
      }
    }
    auto print = [&](auto& t) {
      for (auto& r : t) {
        for (auto& x : r) cout << x << ' ';
        cout << "\n";
      }
      cout << "\n";
    };
    // print(need);
    vector<int> flip_row(n), flip_col(n);
    vector<int> can(n, 1);
    vector good(n, vector<int>(n));
    auto trigger = [&](int x) {
      cout << "trigger " << x << "\n";
      flip_row[x] ^= 1, flip_col[x] ^= 1;
    };
    auto mark = [&](int i, int j) {
      good[i][j] = 1;
      can[i] = 0, can[j] = 0;
    };
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (need[i][j] != 0) {
          int flip = flip_row[i] ^ flip_col[j];
          if ((2 * flip - 1) != need[i][j]) {
            if (can[i]) {
              trigger(i);
              mark(i, j);
            } else if (can[j]) {
              trigger(j);
              mark(i, j);
            }
          } else {
            mark(i, j);
          }
        }
      }
    }
    // print(need);
    // print(good);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if ((need[i][j] == 0 || good[i][j]) == (a[i][j] > a[j][i])) {
          swap(a[i][j], a[j][i]);
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     assert(a[i][j] == i * n + j + 1);
    //   }
    // }
    print(a);
  }
}
