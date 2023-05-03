#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      for (int t = 2; t * t <= x; t++) {
        while (x % t == 0) {
          mp[t]++, x /= t;
        }
      }
      if (x != 1) mp[x]++;
    }
    int cnt = 0, remain = 0;
    for (auto [k, v] : mp) cnt += v / 2, remain += v % 2;
    cout << cnt + remain / 3 << "\n";
  }
}
