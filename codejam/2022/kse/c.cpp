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
  // i -> (2 * i + 1, 2 * i + 2), even, odd
  return p;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    string s;
    cin >> n >> s;
    auto v = manacher(s);
    ll res = n;
    set<ll> start, ending;
    for (int i = 0; i < v.size(); i++) {
      if (i & 1) {
        ll pre = i / 2, wing = v[i] / 2;
        if (pre == wing) {
          start.insert(v[i]);
        }
        if (n - pre == wing) {
          ending.insert(v[i]);
        }
      } else {
        ll pos = (i - 1) / 2, wing = (v[i] - 1) / 2;
        if (pos == wing) {
          start.insert(v[i]);
        }
        if (n - pos - 1 == wing) {
          ending.insert(v[i]);
        }
      }
    }
    for (auto& x : start) {
      if (!x) continue;
      if (ending.count(n - x)) {
        res = min(res, x);
      }
    }
    cout << s.substr(0, res) << "\n";
  }
}
