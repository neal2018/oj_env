#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> pos(k);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i], pos[i % k].push_back(i);
  }
  auto copy = pos;
  for (auto& v : pos) {
    sort(v.begin(), v.end(), [&](const auto x, const auto y) { return a[x] < a[y]; });
  }
  vector<int> b(n);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < pos[i].size(); j++) {
      b[copy[i][j]] = a[pos[i][j]];
    }
  }
  cout << (is_sorted(b.begin(), b.end()) ? "Yes\n" : "No\n");
}
