#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, k;
  string s;
  cin >> n >> m >> k >> s;
  ll x_cnt = count(s.begin(), s.end(), 'x');
  auto check = [&](ll mid) {

    ll full_cnt = mid / n;
    ll remain = mid % n;
    ll need = full_cnt * x_cnt;

    ll at_least = 2 * n, cur = 0;
    for (int j = 0; j < remain; j++) {
      cur += (s[j] == 'x');
    }

    for (ll i = 0, j = mid; j <= n * m && i < 2 * n; i++, j++) {
      at_least = min(at_least, cur);
      cur -= (s[i % n] == 'x');
      if (j != n * m) {
        cur += (s[j % n] == 'x');
      }
    }

    return at_least + need <= k;
  };

  ll l = 0, r = n * m;

  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
}
