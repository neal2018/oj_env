#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> row(n), col(n), deg(2 * n);
  vector<vector<int>> g(2 * n);
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x, a[i][j] = x;
      if (x == -1) {
        g[i].push_back(n + j), g[n + j].push_back(i);
        deg[i]++, deg[n + j]++;
      } else {
        row[i] ^= x, col[j] ^= x;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    row[i] ^= x;
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    col[i] ^= x;
  }
  vector<int> q, nq, seen(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    if (deg[i] == 1) q.push_back(i);
  }
  for (; q.size(); swap(q, nq), nq.clear()) {
    for (auto& node : q) {
      seen[node] = 1;
      for (auto& ne : g[node]) {
        if (seen[ne] == 0) {
          if (ne < node) {
            a[ne][node - n] = col[node - n];
            row[ne] ^= col[node - n];
          } else {
            a[node][ne - n] = row[node];
            col[ne - n] ^= row[node];
          }
          if (--deg[ne] == 1) {
            nq.push_back(ne);
          }
        }
      }
    }
  }
  for (auto& r : a) {
    for (auto& x : r) {
      if (x == -1) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  for (auto& r : a) {
    for (auto& x : r) cout << x << " ";
    cout << "\n";
  }
}
