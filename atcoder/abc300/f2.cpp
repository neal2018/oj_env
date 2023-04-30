#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  string s;
  cin >> n >> m >> k >> s;
  ll x_cnt = count(s.begin(), s.end(), 'x');

  ll full_cnt = k / x_cnt;
  ll remain = k - full_cnt * x_cnt;
  ll res = 0;

  for (ll i = 0, j = full_cnt * n, cur = 0; i < 3 * n && j <= n * m;) {
    while (cur > remain) {
      cur -= (s[i % n] == 'x'), i++;
    }
    res = max(res, j - i);
    cur += (s[j % n] == 'x'), j++;
  }

  cout << res << "\n";
}
