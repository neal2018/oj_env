#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(n, vector<int>(n));
  for (auto& r : a) {
    for (auto& x : r) cin >> x;
  }
  vector b(n, vector<int>(n));
  for (auto& r : b) {
    for (auto& x : r) cin >> x;
  }

  auto check = [&](const auto& aa, const auto& bb) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (!bb[i][j] && aa[i][j]) return false;
      }
    }
    return true;
  };

  auto rotate = [&](const auto& aa) {
    auto res = aa;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        res[n - 1 - j][i] = aa[i][j];
      }
    }
    return res;
  };
  for (int i = 0; i < 4; i++) {
    if (check(a, b)) {
      cout << "Yes\n";
      return 0;
    }
    a = rotate(a);
  }
  cout << "No\n";
}
