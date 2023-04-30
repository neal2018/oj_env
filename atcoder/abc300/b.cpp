#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<string> b(n);
  for (auto& x : b) cin >> x;
  auto shift = [&](const vector<string>& v, int s, int t) {
    auto res = v;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res[i][j] = v[((i - s) + n) % n][((j - t) + m) % m];
      }
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (shift(a, i, j) == b) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
}
