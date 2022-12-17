#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& x : a) cin >> x;

    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == '1') {
          g[i].push_back(j);
          deg[j]++;
        }
      }
    }
    vector<__int128> res(n);
    vector<int> q, nq;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) q.push_back(i);
    }
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        res[node] |= (__int128(1) << node);
        for (auto& ne : g[node]) {
          res[ne] |= res[node];
          if (--deg[ne] == 0) nq.push_back(ne);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      vector<int> out;
      for (int t = 0; t < n; t++) {
        if (res[i] & (__int128(1) << t)) out.push_back(t);
      }
      cout << out.size() << " ";
      for (auto& x : out) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    }
  }
}
