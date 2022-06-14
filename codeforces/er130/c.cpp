#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    string s, t;
    cin >> n >> s >> t;
    {
      ll b_s = count(s.begin(), s.end(), 'b');
      ll t_s = count(t.begin(), t.end(), 'b');
      if (b_s != t_s) {
        cout << "NO\n";
        continue;
      }
    }
    if (s == t) {
      cout << "YES\n";
      continue;
    }
    auto get = [](string ss) {
      string ac;
      vector<int> b;
      int cur = 0;
      for (auto& c : ss) {
        if (c == 'b') {
          cur++;
        } else {
          b.push_back(cur);
          cur = 0;
          ac += c;
        }
      }
      b.push_back(cur);
      return pair{ac, b};
    };
    auto&& [ac_s, b_s] = get(s);
    auto&& [ac_t, b_t] = get(t);
    if (ac_s != ac_t) {
      cout << "NO\n";
      continue;
    }
    cout << ([&] {
      ll sz = b_s.size();
      for (int i = 0; i < sz; i++) {
        if (b_s[i] == b_t[i]) {
          continue;
        } else if (b_s[i] < b_t[i]) {
          if (i == sz - 1 || ac_s[i] != 'a') {
            return false;
          }
          if (i != sz - 1) {
            b_s[i + 1] -= b_t[i] - b_s[i];
          }
        } else {
          if (i == sz - 1 || ac_s[i] != 'c') {
            return false;
          }
          if (i != sz - 1) {
            b_s[i + 1] -= b_t[i] - b_s[i];
          }
        }
      }
      return true;
    }()
                 ? "YES\n"
                 : "NO\n");
  }
}
