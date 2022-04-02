#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; case_num++) {
    cout << "Case #" << case_num << ": ";
    ll n;
    cin >> n, n++;
    vector<ll> a(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    vector<vector<ll>> g(n);
    for (int i = 1, u; i < n; i++) {
      cin >> u, g[u].push_back(i);
    }
    vector<ll> mini(n, 1e18);
    function<void(int)> dfs = [&](int node) {
      for (auto& ne : g[node]) {
        dfs(ne);
        mini[node] = min(mini[node], max(mini[ne], a[node]));
      }
      if (mini[node] == 1e18) mini[node] = a[node];
    };
    dfs(0);
    ll res = 0;
    function<void(int, ll)> solve = [&](int node, ll up) {
      up = max(a[node], up);
      int pos = -1;
      for (auto& ne : g[node]) {
        if (pos == -1 || mini[ne] < mini[pos]) pos = ne;
      }
      if (pos == -1) {
        res += up;
      } else {
        for (auto& ne : g[node]) {
          if (ne == pos) {
            solve(ne, up);
          } else {
            solve(ne, a[ne]);
          }
        }
      }
    };
    solve(0, 0);
    cout << res << "\n";
  }
}