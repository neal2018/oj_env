#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    ll n;
    cin >> n, n++;
    vector<vector<int>> g(n);
    vector<int> deg_o(n);
    for (int i = 1, k; i < n; i++) {
      cin >> k, deg_o[i] = k;
      for (int j = 0, x; j < k; j++) {
        cin >> x, g[x].push_back(i);
      }
    }
    auto deg = deg_o;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);
    int res = 0;
    vector<int> seen(n);
    for (auto& start : order) {
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
