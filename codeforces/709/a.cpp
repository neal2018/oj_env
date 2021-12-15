#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  auto func = [&]() {
    int n, m, can = 1;
    cin >> n >> m;
    vector<int> k(m), res(m, -1), cnt(n);
    vector<vector<int>> f(m);
    for (int i = 0; i < m; i++) {
      cin >> k[i];
      for (int j = 0, x; j < k[i]; j++) {
        cin >> x, x--;
        f[i].push_back(x);
      }
      if (k[i] == 1) {
        int x = f[i][0];
        res[i] = x;
        cnt[x]++;
      }
      if (k[i] == 0) can = 0;
    }
    if (can == 0) {
      cout << "NO\n";
      return;
    }
    for (auto& x : cnt) {
      if (x > (m + 1) / 2) {
        cout << "NO\n";
        return;
      }
    }
    for (int i = 0; i < m; i++) {
      if (res[i] != -1) continue;
      for (auto& x : f[i]) {
        if (cnt[x] < (m + 1) / 2) {
          res[i] = x;
          cnt[x]++;
          break;
        }
      }
    }
    cout << "YES\n";
    for (auto& x : res) cout << x + 1 << ' ';
    cout << '\n';
  };
  for (; T--;) func();
}