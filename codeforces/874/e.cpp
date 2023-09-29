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
    vector<int> a(n);
    for (auto& x : a) cin >> x, x--;
    vector<set<int>> g(n);
    for (int i = 0; i < n; i++) {
      if (g[i].count(a[i]) == 0) {
        g[i].insert(a[i]);
        g[a[i]].insert(i);
      }
    }
    int ring = 0, line = 0;
    vector<int> seen(n);
    for (int i = 0; i < n; i++) {
      if (seen[i]) continue;
      bool is_ring = true;
      vector<int> q{i}, nq;
      seen[i] = 1;
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          if (g[node].size() != 2) is_ring = false;
          for (auto& ne : g[node]) {
            if (seen[ne]) continue;
            seen[ne] = 1;
            nq.push_back(ne);
          }
        }
      }
      if (is_ring) {
        ring++;
      } else {
        line++;
      }
    }
    int mini = ring + (line > 0);
    int maxi = ring + line;
    cout << mini << " " << maxi << "\n";
  }
}
