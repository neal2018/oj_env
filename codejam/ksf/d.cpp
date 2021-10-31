#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define IO
ll INF = 1e18;

int main(int, char**) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll total_cases_number, n, m, k, u, v;
  cin >> total_cases_number;
  for (ll case_num = 1; case_num <= total_cases_number; case_num++) {
    cin >> n >> m >> k;
    vector<ll> l(n), r(n), a(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i] >> a[i];
    }
    vector<vector<ll>> g(n, vector<ll>(n));
    for (int i = 0; i < m; i++) {
      cin >> u >> v;
      g[u][v] = 1;
      g[v][u] = 1;
    }
    ll res = 0;
    vector<ll> order(n);
    iota(order.begin(), order.end(), 0);
    do {
      vector<int> reach(n);
      ll cur = a[order[0]], f = 0;
      if (cur == k) {
        res += 1;
        continue;
      }
      for (int i = 0; i < n; i++)
        if (g[order[0]][i]) reach[i] = 1;

      for (int x = 1; x < n; x++) {
        ll i = order[x];
        if (cur >= l[i] && cur <= r[i] && reach[i]) {
          cur += a[i];
          if (cur == k) {
            f = 1;
            break;
          }
          for (int j = 0; j < n; j++)
            if (g[i][j]) reach[j] = 1;
        } else {
          break;
        }
      }
      res += f;
    } while (next_permutation(order.begin(), order.end()));

    cout << "Case #" << case_num << ": " << res << '\n';
    
  }
  return 0;
}
