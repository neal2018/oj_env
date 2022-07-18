#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    auto get = [&](const string& ss) {
      vector<pair<int, int>> res;
      for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && ss[i] == ss[j];) j++;
        if (ss[i] == '1') res.push_back({i, j});
      }
      return res;
    };
    auto ps = get(s), pt = get(t);
    if (s[0] != t[0] || s.back() != t.back() || ps.size() != pt.size()) {
      cout << "-1\n";
      continue;
    }
    ll res = 0;
    for (int i = 0; i < ps.size(); i++) {
      auto [l1, r1] = ps[i];
      auto [l2, r2] = pt[i];
      res += abs(l1 - l2) + abs(r1 - r2);
    }
    cout << res << "\n";
  }
}
