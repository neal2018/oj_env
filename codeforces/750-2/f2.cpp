#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, maxi = 1 << 13, res = 0, inf = 1e9;
  cin >> n;
  vector<set<int>> st(maxi + 1);
  for (int i = 0; i < n; i++) {
    cin >> a;
    st[a].insert(i);
  }
  vector<int> f(maxi + 1, inf);
  f[0] = -1;
  for (int i = 0; i <= maxi; i++) {
    for (int j = 0; j <= maxi; j++) {
      auto it = st[i].upper_bound(f[j]);
      if (it != st[i].end()) {
        if (f[i ^ j] == inf) res++;
        f[i ^ j] = min(f[i ^ j], *it);
      }
    }
  }
  cout << res + 1 << '\n';
  for (int i = 0; i <= maxi; i++) {
    if (f[i] < inf) cout << i << " \n"[i == n];
  }
}