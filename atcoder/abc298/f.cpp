#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<array<ll, 3>> a(n);
  map<array<ll, 2>, ll> numbers;
  map<ll, vector<array<ll, 2>>> row;
  map<ll, ll> col;
  set<array<ll, 2>> val2col;
  auto add = [&](ll y, ll z) {
    val2col.erase({-col[y], y});
    col[y] += z;
    val2col.insert({-col[y], y});
  };
  for (auto& [x, y, z] : a) {
    cin >> x >> y >> z;
    numbers[{x, y}] = z;
    row[x].push_back({y, z});
    add(y, z);
  }
  ll res = 0;
  for (auto& [r, points] : row) {
    ll cur = 0;
    for (auto& [c, v] : points) {
      cur += v;
      add(c, -v);
    }
    cur += -(*val2col.begin())[0];
    res = max(res, cur);
    for (auto& [c, v] : points) {
      add(c, v);
    }
  }
  cout << res << "\n";
}
