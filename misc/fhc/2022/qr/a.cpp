#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
      cin >> x, mp[x]++;
    }
    if (n > 2 * k) {
      cout << "NO\n";
      continue;
    }
    [&]() {
      for (auto& [kk, v] : mp) {
        if (v > 2) {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
    }();
  }
}
