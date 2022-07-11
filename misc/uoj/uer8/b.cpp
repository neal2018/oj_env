#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<array<ll, 3>> b(m);
  ll total = 0;
  for (auto& [x, y, z] : b) {
    cin >> x >> y >> z, total += z;
  }
  if (total < n) {
    cout << "-1\n";
    return 0;
  }
  ll res = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q0, q1;
  auto insert_mouse = [&](ll pos) {
    auto [val, d] = q1.top();
    q1.pop();
    res += val + pos;
    q0.emplace(-pos * 2 - val, 1);
    if (d > 1) q1.emplace(val, d - 1);
  };
  auto insert_hole = [&](ll pos, ll weight, ll count) {
    ll f = 0;
    for (; f < count && q0.size() && q0.top().first + pos + weight < 0;) {
      auto [val, d] = q0.top();
      q0.pop();
      ll add = min(d, count - f);
      res += (val + pos + weight) * add;
      f += add;
      if (d > add) q0.emplace(val, d - add);
      q1.emplace(-pos * 2 - val, add);
    }
    if (f < count) q1.emplace(-pos + weight, count - f);
    if (f) q0.emplace(-pos - weight, f);
  };
  insert_hole(-inf, 0, n);
  for (int i = 0, j = 0; i < n || j < m;) {
    if (j == m || (i != n && a[i] <= b[j][0])) {
      insert_mouse(a[i]), i++;
    } else {
      insert_hole(b[j][0], b[j][1], b[j][2]), j++;
    }
  }
  cout << res << "\n";
}
