#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

ll calc(ll l, ll r) {
  if (l < 0 && r > 0) return 0;
  if (l >= 0) {
    ll b = (1 << 30);
    while (true) {
      if (l / b * b + b < r) return l / b * b + b;
      b /= 2;
    }
  } else {
    return -calc(-r, -l);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<string> s(n);
  for (auto& x : s) cin >> x;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) swap(s[i][j], s[j][i]);

  map<string, ll> mp;
  function<ll(string)> dfs = [&](string s) {
    if (mp.count(s)) return mp[s];
    ll maxi = -1e18;
    for (int i = 0; i < n; i++) {
      string ns = s;
      if (ns[i] == 'B') {
        ns[i] = '.';
        maxi = max(maxi, dfs(ns));
      } else if (i + 1 < n && ns[i] == '.' && ns[i + 1] == 'W') {
        ns[i] = 'W', ns[i + 1] = '.';
        maxi = max(maxi, dfs(ns));
      }
    }
    ll mini = 1e18;
    for (int i = 0; i < n; i++) {
      string ns = s;
      if (ns[i] == 'W') {
        ns[i] = '.';
        mini = min(mini, dfs(ns));
      } else if (i + 1 < n && ns[i] == '.' && ns[i + 1] == 'B') {
        ns[i] = 'B', ns[i + 1] = '.';
        mini = min(mini, dfs(ns));
      }
    }
    return mp[s] = calc(maxi, mini);
  };

  ll res = 0;
  for (int i = 0; i < n; i++) res += dfs(s[i]);
  cout << ((res > 0) ? "Takahashi\n" : "Snuke\n");
}