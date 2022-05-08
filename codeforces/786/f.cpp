#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, q;
  cin >> n >> m >> q;
  ll cnt = 0;
  vector<string> a(n);
  for (auto& x : a) {
    cin >> x;
    cnt += count(x.begin(), x.end(), '*');
  }
  pair<ll, ll> pos = {cnt % n, cnt / n};
  ll cur = 0;
  for (int j = 0; j < pos.second; j++) {
    for (int i = 0; i < n; i++) {
      cur += a[i][j] == '*';
    }
  }
  for (int i = 0; i < pos.first; i++) {
    cur += a[i][pos.second] == '*';
  }
  auto pre = [&](pair<ll, ll> t) {
    t.first--;
    if (t.first < 0) {
      t.second--;
      t.first = n - 1;
    }
    return t;
  };
  auto nex = [&](pair<ll, ll> t) {
    t.first++;
    if (t.first == n) {
      t.second++;
      t.first = 0;
    }
    return t;
  };
  while (q--) {
    ll x, y;
    cin >> x >> y, x--, y--;
    if (a[x][y] == '.') {
      a[x][y] = '*';
      cnt++;
      if (y * m + x < pos.second * m + pos.first) {
        cur++;
      }
      cur += a[pos.first][pos.second] == '*';
      pos = nex(pos);
      cout << cnt - cur << "\n";
    } else {
      a[x][y] = '.';
      cnt--;
      if (y * m + x < pos.second * m + pos.first) {
        cur--;
      }
      pos = pre(pos);
      cur -= a[pos.first][pos.second] == '*';
      cout << cnt - cur << "\n";
    }
  }
}
