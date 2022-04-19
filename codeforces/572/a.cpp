#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<int> deg(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v, u--, v--;
    deg[u]++, deg[v]++;
  }
  for (auto& x : deg) {
    if (x == 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}