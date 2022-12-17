#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    string rev_b;
    for (auto& c : b) rev_b += (c ^ '0' ^ '1');
    if (a != b && a != rev_b) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int flip = (a == rev_b);
    vector<pair<int, int>> res;
    for (int i = 0, j = 0; i < n; i = j) {
      for (j = i; j < n && a[i] == a[j];) j++;
      if (a[i] == '1') {
        res.push_back({i, j - 1});
        flip ^= 1;
      }
    }
    if (flip) {
      res.push_back({0, n - 1});
      res.push_back({0, 0});
      res.push_back({1, n - 1});
    }
    cout << res.size() << "\n";
    for (auto& [x, y] : res) {
      cout << x + 1 << " " << y + 1 << "\n";
    }
  }
}
