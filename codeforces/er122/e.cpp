#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> edges(m);
  vector<int> ws;
  ws.reserve(m * m);
  for (auto& [w, u, v] : edges) {
    cin >> u >> v >> w, u--, v--;
    ws.push_back(w);
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      ws.push_back((ws[i] + ws[j] + 1) / 2);
    }
  }
  ws.push_back(0);
  sort(ws.begin(), ws.end());
  ws.erase(unique(ws.begin(), ws.end()), ws.end());
  ll sz = ws.size();
  vector<ll> aa(sz), bb(sz);
  vector<int> p(n);
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  for (int i = 0; i < sz; i++) {
    sort(edges.begin(), edges.end(), [&](auto x, auto y) {
      return pair{abs(x[0] - ws[i]), -x[0]} < pair{abs(y[0] - ws[i]), -y[0]};
    });
    iota(p.begin(), p.end(), 0);
    for (auto& [w, u, v] : edges) {
      if (find(u) != find(v)) {
        merge(u, v);
        if (ws[i] >= w) {
          aa[i]++, bb[i] -= w;
        } else {
          aa[i]--, bb[i] += w;
        }
      }
    }
  }
  ll res = 0, pp, k, a, b, c, x;
  cin >> pp >> k >> a >> b >> c;
  for (int i = 0; i < k; i++) {
    if (i < pp) {
      cin >> x;
    } else {
      x = (a * x + b) % c;
    }
    ll pos = upper_bound(ws.begin(), ws.end(), x) - ws.begin() - 1;
    ll w = aa[pos] * x + bb[pos];
    res ^= w;
  }
  cout << res << "\n";
}