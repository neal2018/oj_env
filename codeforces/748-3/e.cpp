#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k, u, v;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<ll> deg(n), q, nq, seen(n);
    for (int i = 0; i < n - 1; i++) {
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
      deg[v]++, deg[u]++;
    }
    for (int i = 0; i < n; i++)
      if (deg[i] <= 1) q.push_back(i), seen[i] = 1;
    ll remove = 0;
    for (ll step = 0; step < k && q.size(); swap(q, nq), nq.clear(), step++) {
      for (int node : q) {
        remove++;
        for (int ne : g[node]) {
          deg[ne]--;
          if (deg[ne] <= 1 && !seen[ne]) nq.push_back(ne), seen[ne] = 1;
        }
      }
    }
    cout << n - remove << '\n';
  }
}