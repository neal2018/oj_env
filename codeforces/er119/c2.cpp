#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n, k, x;
  cin >> T;
  while (T--) {
    cin >> n >> k >> x, x--;
    string s, res = "";
    cin >> s;
    reverse(s.begin(), s.end());
    ll cnt = 0;
    for (auto c : s) {
      if (c == 'a') {
        res += string(x % (k * cnt + 1), 'b');
        res += c;
        x /= (k * cnt + 1), cnt = 0;
      } else {
        cnt++;
      }
    }
    res += string(x % (k * cnt + 1), 'b');
    reverse(res.begin(), res.end());
    cout << res << '\n';
  }
}