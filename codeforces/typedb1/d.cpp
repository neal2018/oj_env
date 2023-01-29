#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<int> a(n), nex(n), indeg(n), outdeg(n);
    vector<vector<int>> rev(n);
    for (auto& x : a) cin >> x;
    for (int i = 0; i < n; i++) {
      nex[i] = i + a[i];
      if (nex[i] < 0 || nex[i] >= n) {
        nex[i] = -1;
      } else {
        indeg[nex[i]]++;
        outdeg[i]++;
        rev[nex[i]].push_back(i);
      }
    }
    vector<int> to_ring(n), seen(n);
    auto go = [&](int i) {
      int cur = i;
      while (true) {
        seen[cur] = i + 1;
        if (nex[cur] != -1 && seen[nex[cur]] == 0) {
          cur = nex[cur];
        } else {
          break;
        }
      }
      if (nex[cur] == -1) return;
      int start = cur;
      int record = nex[cur];
      if (seen[record] == i + 1) {
        for (cur = i;;) {
          to_ring[cur] = 1;
          if (cur == start) break;
          cur = nex[cur];
        }
      } else {
        for (cur = i;;) {
          to_ring[cur] = to_ring[record];
          if (cur == start) break;
          cur = nex[cur];
        }
      }
    };
    for (int i = 0; i < n; i++) {
      if (indeg[i] != 0) continue;
      go(i);
    }
    for (int i = 0; i < n; i++) {
      if (seen[i] != 0) continue;
      go(i);
    }
    ll res = 0;
    ll total_to_ring = accumulate(to_ring.begin(), to_ring.end(), 0);
    if (!to_ring[0]) {
      vector<ll> sz(n);
      function<void(int, int)> dfs = [&](int node, int fa) {
        sz[node] = 1;
        for (auto& ne : rev[node]) {
          if (ne == fa) continue;
          dfs(ne, node);
          sz[node] += sz[ne];
        }
      };
      for (int i = 0; i < n; i++) {
        if (outdeg[i] == 0) dfs(i, -1);
      }
      ll connected = 0;
      for (int cur = 0; cur != -1; cur = nex[cur]) {
        connected++;
      }
      res += (n - connected) * (2 * n + 1);
      for (int cur = 0; cur != -1; cur = nex[cur]) {
        res += (2 * n + 1 - sz[cur] - total_to_ring);
      }
    } else {
      for (int cur = 0; cur != -1 && seen[cur] != -1; cur = nex[cur]) {
        res += (2 * n + 1 - total_to_ring);
        seen[cur] = -1;
      }
    }
    cout << res << "\n";
  }
}