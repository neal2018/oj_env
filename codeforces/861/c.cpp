#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll l, r;
    cin >> l >> r;
    auto ls = to_string(l), rs = to_string(r);
    if (ls.size() != rs.size()) {
      for ([[maybe_unused]] auto& _ : ls) cout << "9";
      cout << "\n";
      continue;
    }
    string res = ls;
    int min_diff = 9;
    int pos = 0;
    while (ls[pos] == rs[pos]) pos++;
    if (pos == ls.size()) {
      cout << res << "\n";
      continue;
    }
    auto get_diff = [&](string_view s) {
      auto [mini, maxi] = minmax_element(s.begin(), s.end());
      auto diff = *maxi - *mini;
      return diff;
    };
    {
      string s = rs;
      if (pos < int(ls.size()) - 1) {
        if (rs[pos + 1] > rs[pos]) {
          for (int j = pos + 1; j < rs.size(); j++) {
            s[j] = s[pos];
          }
        } else {
          int has_cave = 0;
          for (int i = pos + 1; i < rs.size(); i++) {
            if (rs[i] > rs[i - 1]) has_cave = 1;
            if (!has_cave && rs[i] < rs[pos + 1]) {
              char c = rs[pos + 1] - 1;
              for (int j = pos + 1; j < rs.size(); j++) {
                s[j] = c;
              }
              break;
            } else {
              s[i] = rs[pos + 1];
            }
          }
        }
      }
      int diff = get_diff(s);
      if (diff < min_diff) min_diff = diff, res = s;
    }
    {
      string s = ls;
      if (pos < int(ls.size()) - 1) {
        if (ls[pos + 1] < ls[pos]) {
          for (int j = pos + 1; j < ls.size(); j++) {
            s[j] = s[pos];
          }
        } else {
          int has_cave = 0;
          for (int i = pos + 1; i < ls.size(); i++) {
            if (ls[i] < ls[i - 1]) has_cave = 1;
            if (!has_cave && ls[i] > ls[pos + 1]) {
              char c = ls[pos + 1] + 1;
              for (int j = pos + 1; j < ls.size(); j++) {
                s[j] = c;
              }
              break;
            } else {
              s[i] = ls[pos + 1];
            }
          }
        }
      }
      int diff = get_diff(s);
      if (diff < min_diff) min_diff = diff, res = s;
    }

    if (rs[pos] - ls[pos] > 1) {
      for (char c = ls[pos] + 1; c < rs[pos]; c++) {
        string s = rs;
        for (int i = pos; i < s.size(); i++) {
          s[i] = c;
        }
        int diff = get_diff(s);
        if (diff < min_diff) min_diff = diff, res = s;
      }
    }
    cout << res << "\n";
  }
}
