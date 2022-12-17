#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  ll c1, c2;
  cin >> c1 >> c2;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector dist(n, vector(m, inf));
  priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
        dist[i][j] = 0;
        pq.push({0, i, j});
      }
    }
  }
  while (pq.size()) {
    auto [cost, i, j] = pq.top();
    pq.pop();
    if (i >= 2) {  // left
      if (a[i - 2][j] == 'L' && a[i - 1][j] == 'R') {
        if (c2 + cost < dist[i - 2][j]) {
          dist[i - 2][j] = c2 + cost;
          pq.push({dist[i - 2][j], i - 2, j});
        }
      }
    }
    if (i + 2 < n) {  // right
      if (a[i + 1][j] == 'L' && a[i + 2][j] == 'R') {
        if (c2 + cost < dist[i + 2][j]) {
          dist[i + 2][j] = c2 + cost;
          pq.push({dist[i + 2][j], i + 2, j});
        }
      }
    }

  }
}
