#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> seen(210);
    for (auto& x : a) seen[x] = 1;
    for (int i = 1; i < 210; i++) {
      if (seen[i] == 0) {
        if (m) {
          m--;
        } else {
          cout << i - 1 << "\n";
          break;
        }
      }
    }
  }
}
