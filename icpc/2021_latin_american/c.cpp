#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(auto from, auto to, int target) {
  int delta = 0;
  int min_delta = 2e9;
  auto start_at = from;
  int cnt = 0;
  for (auto now = from; now != to; ++now) {
    ++cnt;
    delta += *now - target;
    if (delta < min_delta) {
      min_delta = delta;
      start_at = now;
    }
  }
  ++start_at;
  ll cost = 0;
  while (cnt--) {
    cost += delta;
    if (start_at == to) start_at = from;
    delta += *start_at - target;
    ++start_at;
  }
  return cost;
}

auto main() -> int {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  auto a = vector<int>(n);
  int glasses_per_table = 0;
  for (auto& x : a) {
    cin >> x;
    glasses_per_table += x;
  }
  glasses_per_table /= n;

  auto cw = solve(a.cbegin(), a.cend(), glasses_per_table);
  auto ccw = solve(a.crbegin(), a.crend(), glasses_per_table);

  cout << std::min(cw, ccw) << '\n';

  return 0;
}
