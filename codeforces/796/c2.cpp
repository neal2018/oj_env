#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    for (int i = 0, x; i < n; i++) cin >> x, a[i] -= x;
    vector<pair<int, int>> segs(m);
    vector<vector<int>> edges(n + 1);
    for (auto i : views::iota(0, m)) {
      auto& [l, r] = segs[i];
      cin >> l >> r, l--;
      edges[l].push_back(i), edges[r].push_back(i);
    }
    vector<ll> pre(n + 1);
    for (auto i : views::iota(0, n)) pre[i + 1] = pre[i] + a[i];

    vector<ll> p(n + 2);
    iota(p.begin(), p.end(), 0);
    function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
    auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };

    vector<ll> q, nq;
    for (auto i : views::iota(0, n + 1)) {
      if (pre[i] == 0) q.push_back(i), merge(i, i + 1);
    }
    vector<int> deg(m, 2);
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        for (auto& s : edges[node]) {
          deg[s]--;
          if (deg[s] == 0) {
            for (ll x = find(segs[s].first); x <= segs[s].second; x = find(x)) {
              nq.push_back(x), merge(x, x + 1);
            }
          }
        }
      }
    }
    cout << (find(0) == n + 1 ? "YES\n" : "NO\n");
  }
}
