#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, t;
  cin >> n >> m >> t;
  vector<ll> cost(n - 1), add(n);
  for (auto& x : cost) cin >> x;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y, x--;
    add[x] += y;
  }
  for (int i = 0; i < n - 1; i++) {
    t += add[i];
    t -= cost[i];
    if (t <= 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
