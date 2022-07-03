#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<array<int, 3>> a(n + m);
  for ([[maybe_unused]] int i = 0, x = 0; i < n; i++) {
    cin >> x, a[i] = {x, 0, 0};
  }
  for ([[maybe_unused]] int i = 0, x, y; i < m; i++) {
    cin >> x >> y, a[i + n] = {x, 1, y};
  }
  sort(a.begin(), a.end());
  priority_queue<int> pq;
  ll res = 0;
  for (auto& [x, is_enemy, bonus] : a) {
    if (is_enemy) {
      pq.push(bonus - x);
    } else {
      if (pq.top() + x > 0) {
        res += x + pq.top();
        pq.pop();
        pq.push(-x);
      }
    }
  }
  cout << res << "\n";
}
