#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e18;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + m);
  vector<ll> dist(n + m, inf);
  for (int i = 0; i < n; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 0, x; j < cnt; j++) {
      cin >> x, x--;
      g[i].push_back(n + x);
      g[n + x].push_back(i);
      if (x == 0) dist[i] = 0;
    }
  }
  auto dij = [&](vector<ll>& dist) {
    set<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) st.insert({dist[i], i});
    while (st.size()) {
      auto [c, node] = *st.begin();
      st.erase(st.begin());
      for (auto& ne : g[node]) {
        int w = 1;
        if (w + c < dist[ne]) {
          dist[ne] = w + c;
          st.insert({dist[ne], ne});
        }
      }
    }
  };
  dij(dist);
  if (dist[n + m - 1] == inf) {
    cout << "-1\n";
  } else {
    cout << (dist[n + m - 1] / 2) << "\n";
  }
}
