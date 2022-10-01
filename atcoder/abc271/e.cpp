#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 3>> edges(m);
  for (auto& [x, y, z] : edges) {
    cin >> x >> y >> z, x--, y--;
  }
  vector<int> a(k);
  for (auto& x : a) cin >> x, x--;
  vector<ll> dist(inf);
  dist[0] = 0;
  for (auto& x : a) {
    auto [u, v, w] = edges[x];
    if (dist[u] < inf && dist[v] > dist[u] + w) {
      dist[v] = dist[u] + w;
    }
  }
  cout << (dist[n - 1] >= inf ? -1 : dist[n - 1]) << "\n";
}
