#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  ll x = 0;
  pair<int, int> res{1, -1};
  for (int len = 1; len <= n; len++) {
    x = (10 * x + 1) % m;
    for (int t = 1; t <= 9; t++) {
      ll cur = t * x % m;
      if (cur == 0) {
        res = {len, t};
      }
    }
  }
  for (int i = 0; i < res.first; i++) {
    cout << res.second;
  }
  cout << "\n";
}
