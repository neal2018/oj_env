#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d, res = 0;
  cin >> n >> d;
  vector<tuple<int, int, int>> v;
  for (int i = 0, s, a; i < n; i++) {
    cin >> s >> a;
    v.push_back({max(s, a), s, a});
  }
  sort(v.begin(), v.end());
  for (auto [_, s, a] : v) {
    if (s >= d) res++, d = max(d, a);
  }
  cout << res << '\n';
}