#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int m, n;
  cin >> n >> m;
  vector<int> a(m), res(n);
  for (auto& x : a) cin >> x, x--;
  int point = m - 1;
  int cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur++;
    if (a[point] == i) cur = 0;
    res[i] = cur;
    while (point && a[point] >= i) point--;
  }
  for (auto& x : res) cout << x << "\n";
}
