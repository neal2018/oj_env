#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  map<char, char> win{{'S', 'R'}, {'P', 'S'}, {'R', 'P'}};
  while (T--) {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    map<char, ll> cnt{{'R', a}, {'P', b}, {'S', c}};
    string s;
    cin >> s;
    string t(n, '?');
    ll total = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[win[s[i]]]) {
        t[i] = win[s[i]], cnt[win[s[i]]]--, total++;
      }
    }
    if (total >= (n + 1) / 2) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        if (t[i] == '?') {
          for (auto& [k, v] : cnt) {
            if (v) {
              t[i] = k, v--;
              break;
            }
          }
        }
      }
      cout << t << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
