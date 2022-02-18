#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(m));
  for (auto& r : a) {
    for (auto& x : r) cin >> x;
  }
}
