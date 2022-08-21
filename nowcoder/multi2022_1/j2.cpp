#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    ll n;
    cin >> n, n++;
    vector<vector<int>> g(n);
    vector<int> deg_o(n);
    for (int i = 1, k; i < n; i++) {
      cin >> k;
      for (int j = 0, x; j < k; j++) {
        cin >> x;
        g[x].push_back(i);
      }
      deg_o[i] = k;
    }
    vector<int> topo;
    {
      auto deg = deg_o;
      vector<int> q, nq, seen(n);
      for (int i = 0; i < n; i++) {
        if (deg[i] == 0) q.push_back(i);
      }
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          topo.push_back(node), seen[node] = 1;
          for (auto& ne : g[node]) {
            if (--deg[ne] == 0) nq.push_back(ne);
          }
        }
      }
      vector<int> remain;
      for (int i = 0; i < n; i++) {
        if (seen[i] == 0) remain.push_back(i);
      }
      mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
      shuffle(remain.begin(), remain.end(), rng);
      for (auto& x : remain) topo.push_back(x);
    }
    auto deg = deg_o;
    int res = 0;
    vector<int> seen(n);
    for (auto& start : topo) {
      if (seen[start] || start == 0) continue;
      deg[start] = 0;
      vector<int> q{start}, nq, cur, involved{start};
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto& node : q) {
          cur.push_back(node);
          for (auto& ne : g[node]) {
            involved.push_back(ne);
            if (--deg[ne] == 0) nq.push_back(ne);
          }
        }
      }
      res = max(res, int(cur.size()));
      for (auto& x : cur) seen[x] = 1;
      for (auto& x : involved) deg[x] = deg_o[x];
    }
    cout << "Case #" << tt + 1 << ": " << res << "\n";
  }
}
