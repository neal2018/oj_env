#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    auto b = a;
    for (auto& r : b) sort(r.begin(), r.end());
    int f = 1;
    vector<int> need;
    {
      ll cnt = 0;
      for (int j = 0; j < m && f; j++) {
        if (a[0][j] != b[0][j]) {
          cnt++;
          if (cnt > 2) {
            f = 0;
          } else {
            need.push_back(j);
          }
        }
      }
    }
    for (int i = 1; i < n && f; i++) {
      vector<int> cur;
      ll cnt = 0;
      for (int j = 0; j < m && f; j++) {
        if (a[i][j] != b[i][j]) {
          cnt++;
          if (cnt > 2) {
            f = 0;
          } else {
            cur.push_back(j);
          }
        }
      }
      if (f) {
        if (cur == need) continue;
        if (cur.size() == 2 && need.size() == 0) {
          if (a[0][cur[0]] == a[0][cur[1]]) {
            need = cur;
            continue;
          }
        }
        if (cur.size() == 0 && need.size() == 2) {
          if (a[i][need[0]] == a[i][need[1]]) {
            continue;
          }
        }
        f = 0;
      }
    }
    if (!f) {
      cout << "-1\n";
      continue;
    }
    if (need.size() == 0) {
      cout << "1 1\n";
    } else {
      cout << need[0] + 1 << " " << need[1] + 1 << "\n";
    }
  }
}
