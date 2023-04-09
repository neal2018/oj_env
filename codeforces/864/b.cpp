#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector a(n, vector<int>(n));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    auto need = a;
    reverse(need.begin(), need.end());
    for (auto& v : need) {
      reverse(v.begin(), v.end());
    }

    int diff = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        diff += (a[i][j] != need[i][j]);
      }
    }
    diff /= 2;
    if (diff <= k && (n % 2 == 1 || (k - diff) % 2 == 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
