#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<int> sq;
  for (int i = 1; i * i <= n; i++) sq.push_back(i * i);
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int t = 1;
    for (auto& x : sq) {
      if (i % x == 0) t = x;
    }
    mp[i / t]++;
  }
  ll res = 0;
  for (auto& [k, v] : mp) res += ll(v) * v;
  cout << res << "\n";
}

