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
    set<ll> st;
    vector<ll> q, nq;
    for (auto i : views::iota(0, n + 1)) {
      if (pre[i] == 0) {
        q.push_back(i);
      } else {
        st.insert(i);
      }
    }
    vector<int> deg(m, 2);
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        for (auto& s : edges[node]) {
          deg[s]--;
          if (deg[s] == 0) {
            auto it_end = st.upper_bound(segs[s].second);
            for (auto it = st.lower_bound(segs[s].first); it != it_end;) {
              nq.push_back(*it), it = st.erase(it);
            }
          }
        }
      }
    }
    cout << (st.size() == 0 ? "YES\n" : "NO\n");
  }
}
