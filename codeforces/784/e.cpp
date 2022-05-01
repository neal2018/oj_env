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
    cin >> n;
    vector<string> a(n);
    for (auto& s : a) cin >> s;
    map<char, ll> mp_start, mp_end;
    map<string, ll> cnt;
    ll res = 0;
    for (auto& s : a) {
      res += mp_start[s[0]] - cnt[s] + mp_end[s[1]] - cnt[s];
      mp_start[s[0]]++, mp_end[s[1]]++;
      cnt[s]++;
    }
    cout << res << "\n";
  }
}
