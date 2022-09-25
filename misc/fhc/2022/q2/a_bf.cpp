#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    string s;
    int m;
    cin >> s >> m;
    int n = int(s.size());
    vector<array<int, 2>> qs;
    qs.reserve(m);
    for (int i = 0, x, y; i < m; i++) {
      cin >> x >> y, x--;
      if ((y - x) % 2 == 1) qs.push_back({x, y});
    }
    m = int(qs.size());
    int SIZE = max(1, (int)(n / sqrt(m)));
    sort(qs.begin(), qs.end(), [&](auto &x, auto &y) {
      return pair{x[0] / SIZE, x[1]} < pair{y[0] / SIZE, y[1]};
    });
    vector<int> seen(26);
    int res = 0;
    int L = 0, R = 0;  //  store [L, R)
    for (auto &[l, r] : qs) {
      vector<int> seen(26);
      for (int i = l; i < r; i++) {
        if (i <= (l + r) / 2) {
          seen[s[i] - 'a']++;
        } else {
          seen[s[i] - 'a']--;
        }
      }
      int t = 0;
      for (auto &x : seen) t += abs(x);
      // cout << l << " " << r << " " << s.substr(l, r - l) << " " << t << "\n";
      auto st = set(seen.begin(), seen.end());
      if (t == 1 || (t == 3 && st == set{0, -1, 2} && seen[s[(l + r) / 2] - 'a'] == 2)) res++;
    }
    cout << res << "\n";
  }
}
