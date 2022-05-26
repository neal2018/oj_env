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
    ll a, b, c, d;
    string s;
    cin >> a >> b >> c >> d >> s;
    ll n = s.size();
    ll cd = n - (a + b + c + d);
    ll a_cnt = count(s.begin(), s.end(), 'A');
    ll b_cnt = count(s.begin(), s.end(), 'B');
    if (a_cnt - cd != a || b_cnt - cd != b) {
      cout << "NO\n";
      continue;
    }
    ll aba = 0, ab = 0, ba = 0, bab = 0;
    vector<ll> a1, a2;
    for (int i = 0, j = 0; i < n; i = j) {
      for (j = i + 1; j < n && s[j - 1] != s[j];) j++;
      if (j == i + 1) continue;
      if (s[i] == 'A' && s[j - 1] == 'B') {
        a1.push_back((j - i) / 2);
        ab += (j - i) / 2;
      }
      if (s[i] == 'A' && s[j - 1] == 'A') {
        aba += (j - i) / 2;
      }
      if (s[i] == 'B' && s[j - 1] == 'B') {
        bab += (j - i) / 2;
      }
      if (s[i] == 'B' && s[j - 1] == 'A') {
        a2.push_back((j - i) / 2);
        ba += (j - i) / 2;
      }
    }
    if (ab - c > 0) {
      sort(a1.begin(), a1.end(), greater());
      for (auto& x : a1) {
        if (ab - 1 < c) break;
        ab--;
        ll avail = min(ab - c, x - 1);
        ab -= avail, ba += avail;
      }
    }
    if (ba - d > 0) {
      sort(a2.begin(), a2.end(), greater());
      for (auto& x : a2) {
        if (ba - 1 < d) break;
        ba--;
        ll avail = min(ba - d, x - 1);
        ba -= avail, ab += avail;
      }
    }
    int f = (max(c - ab, 0ll) + max(d - ba, 0ll) <= aba + bab);
    cout << (f ? "YES\n" : "NO\n");
  }
}
