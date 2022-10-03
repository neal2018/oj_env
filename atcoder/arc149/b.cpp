#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto lis(const vector<int>& a) {
  // strict
  vector<int> piles;
  for (auto& v : a) {
    if (!piles.size() || piles.back() < v) {
      piles.push_back(v);
    } else {
      *lower_bound(piles.begin(), piles.end(), v) = v;
    }
  }
  return int(piles.size());
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) cin >> x;
  for (auto& [x, y] : a) cin >> y;
  int res = 0;
  auto calc = [&] {
    sort(a.begin(), a.end());
    vector<int> t;
    for (auto [x, y] : a) t.push_back(y);
    auto lis2 = lis(t);
    res = max(res, lis2 + n);
  };
  calc();
  for (auto& [x, y] : a) swap(x, y);
  calc();
  cout << res << "\n";
}
