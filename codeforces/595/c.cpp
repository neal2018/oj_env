#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> s;
    ll t = n;
    while (t) {
      s.push_back(t % 3), t /= 3;
    }
    reverse(s.begin(), s.end());
    auto it = find(s.begin(), s.end(), 2);
    if (it == s.end()) {
      cout << n << "\n";
    } else {
      ll j = -1, tt = it - s.begin();
      for (int i = 0; i < tt; i++) {
        if (s[i] == 0) j = i;
      }
      if (j == -1) {
        for (ll i = 0; i < s.size(); i++) s[i] = 0;
        s.insert(s.begin(), 1);
      } else {
        for (ll i = j; i < s.size(); i++) s[i] = 0;
        s[j] = 1;
      }
      ll res = 0;
      for (auto& x : s) {
        res = res * 3 + x;
      }
      cout << res << "\n";
    }
  };
}
