#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

auto manacher(string& s) {
  string t = "^#";
  for (auto& c : s) t += c, t += "#";
  t += "$";
  ll n = t.size(), r = 0, c = 0;
  vector<ll> p(n, 0);
  for (ll i = 1; i < n - 1; i++) {
    if (i < r + c) p[i] = min(p[2 * c - i], r + c - i);
    while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
    if (i + p[i] > r + c) r = p[i], c = i;
  }
  // i -> (2 * i + 1, 2 * i + 2)
  return p;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0, pre = 0, cnt = 0, f = 1;
    auto pp = manacher(s);
    for (ll i = 0; i < n; i++) {
      cnt += (s[i] == '(' ? 1 : -1);
      if (cnt == 0 && f == 1) {
        res++, pre = i + 1;
        continue;
      } else if (cnt < 0) {
        f = 0;
      }
      if (i - pre > 0) {
        if (pp[2 * i + 1] >= 2 * (i - pre)) {
          res++, pre = pre + (i - pre) * 2, cnt = 0, f = 1, i = pre - 1;
        } else if (pp[2 * i + 2] >= 2 * (i - pre) + 1) {
          res++, pre = pre + (i - pre) * 2 + 1, cnt = 0, f = 1, i = pre - 1;
        }
      }
    }
    cout << res << " " << n - pre << "\n";
  };
}
