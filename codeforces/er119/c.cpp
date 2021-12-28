#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k, x;
  cin >> T;
  while (T--) {
    cin >> n >> k >> x;
    string s;
    cin >> s;
    string res = "";
    vector<ll> tt;
    {
      ll pre = 0, cur = 1;
      for (ll i = n - 1; i >= 0; i = pre - 1) {
        pre = i;
        while (pre >= 0 && s[pre] == '*') pre--;
        if (s[i] == 'a') continue;
        ll cnt = i - pre;
        cur *= (k * cnt + 1);
        tt.push_back(k * cnt + 1);
        if (cur >= x) break;
      }
    }
    vector<ll> tt2 = tt;
    ll xx = x - 1;
    for (int i = 0; i < tt.size(); i++) {
      tt2[i] = xx % tt[i];
      xx /= tt[i];
    }
    ll pre = 0, pos = 0;
    for (ll i = n - 1; i >= 0; i = pre - 1) {
      pre = i;
      if (s[i] == 'a') {
        res.push_back('a');
        continue;
      }
      while (pre >= 0 && s[pre] == '*') pre--;
      pre++;
      if (pos < tt.size()) {
        for (int j = 0; j < tt2[pos]; j++) {
          res.push_back('b');
        }
        pos++;
      }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
  }
}