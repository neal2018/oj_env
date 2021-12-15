#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x : a) cin >> x, x--;
    vector<vector<int>> g(n);
    for (int i = 1, p; i < n; i++) {
      cin >> p, p--;
      g[p].push_back(i);
    }
    vector<vector<tuple<int, int, int>>> queries(n);
    for (int i = 0, v, l, k; i < q; i++) {
      cin >> v >> l >> k, v--;
      queries[v].push_back({l, k, i});
    }
    vector<int> res(q), freq(n), cnt(n + 1, n);  // cnt[i] prefix of cnt[0]...cnt[i]
    vector<set<int>> st(n + 1);
    function<void(int, int)> dfs = [&](int node, int fa) {
      int val = a[node];
      freq[val]++;
      st[freq[val]].insert(val);
      if (freq[val] != 1) st[freq[val] - 1].erase(val);
      cnt[freq[val] - 1]--;
      for (auto& [l, k, i] : queries[node]) {
        auto it = lower_bound(cnt.begin() + l, cnt.end(), cnt[l - 1] + k);
        if (it == cnt.end()) {
          res[i] = -2;
        } else {
          res[i] = *st[it - cnt.begin()].begin();
        }
      }
      for (auto& ne : g[node])
        if (ne != fa) dfs(ne, node);
      cnt[freq[val] - 1]++;
      if (freq[val] != 1) st[freq[val] - 1].insert(val);
      st[freq[val]].erase(val);
      freq[val]--;
    };
    dfs(0, -1);
    for (auto& x : res) cout << x + 1 << " ";
    cout << '\n';
  }
}
