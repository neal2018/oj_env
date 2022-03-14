#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  int fill[n + 1];
  memset(fill, 0, sizeof fill);

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j < r; j++) fill[j]++;
  }

  int ans = n + 1;
  for (int i = 0; i < n + 1; i++)
    if (fill[i]) ans += 2;
  cout << ans << '\n';
}
