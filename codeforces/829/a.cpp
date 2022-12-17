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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    auto s = accumulate(a.begin(), a.end(), 0);
    if (s < 0) {
      for (auto& x : a) x = -x;
      s = -s;
    }
    if (s % 2 == 1) {
      cout << "-1\n";
      continue;
    }
    s /= 2;
    vector<int> sign(n);
    vector<array<int, 2>> res;
    for (int i = 0, j; i < n && s > 0; i = j) {
      for (j = i; j < n && a[i] == a[j];) j++;
      if (a[i] < 0) continue;
      int len = j - i;
      int avail = len / 2;
      if (avail == 0) continue;
      if (avail > s) {
        avail = s;
      }
      s -= avail;
      res.push_back({i, i + 1 + (avail - 1) * 2});
    }
    if (s != 0) {
      cout << "-1\n";
      continue;
    }
    int i = 0;
    vector<pair<int, int>> out;
    for (auto& [x, y] : res) {
      while (i < x) {
        out.push_back({i, i}), i++;
      }
      out.push_back({x, y});
      i = y + 1;
    }
    while (i < n) {
      out.push_back({i, i}), i++;
    }
    cout << out.size() << "\n";
    int sum = 0;
    for (auto& [x, y] : out) {
      cout << x + 1 << " " << y + 1 << "\n";
      for (int ii = x; ii <= y; ii++) {
        sum += (a[ii]) * ((ii - x) % 2 ? 1 : -1);
      }
    }
    assert(sum == 0);
  }
}
