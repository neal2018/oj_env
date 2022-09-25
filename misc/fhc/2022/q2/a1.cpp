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
    int cur = 0;
    int two = 0, neg_one = 0;
    auto flip = [&](int i, int d) {
      cur -= abs(seen[i]);
      if (seen[i] == 2) two--;
      if (seen[i] == -1) neg_one--;
      seen[i] += d;
      cur += abs(seen[i]);
      if (seen[i] == 2) two++;
      if (seen[i] == -1) neg_one++;
    };
    auto add_left = [&](int l, int r) {
      flip(s[l - 1] - 'a', 1);
      if ((r - l) % 2 == 1) {
        int mid = (l + r) / 2;
        flip(s[mid] - 'a', -2);
      }
    };
    auto add_right = [&](int l, int r) {
      flip(s[r] - 'a', -1);
      if ((r - l) % 2 == 0) {
        int mid = (l + r) / 2;
        flip(s[mid] - 'a', 2);
      }
    };
    auto del_left = [&](int l, int r) {
      flip(s[l] - 'a', -1);
      if ((r - l) % 2 == 0) {
        int mid = (l + r) / 2;
        flip(s[mid] - 'a', 2);
      }
    };
    auto del_right = [&](int l, int r) {
      flip(s[r - 1] - 'a', 1);
      if ((r - l) % 2 == 1) {
        int mid = (l + r) / 2;
        flip(s[mid] - 'a', -2);
      }
    };
    int L = 0, R = 0;  //  store [L, R)
    for (auto &[l, r] : qs) {
      while (L > l) add_left(L, R), L--;
      while (R < r) add_right(L, R), R++;
      while (L < l) del_left(L, R), L++;
      while (R > r) del_right(L, R), R--;
      // cout << l << " " << r << " " << s.substr(l, r - l) << " " << cur << "\n";
      if (cur == 1 || (two == 1 && neg_one == 1 && cur == 3 && seen[s[(l + r) / 2] - 'a'] == 2))
        res++;
    }
    cout << res << "\n";
  }
}
