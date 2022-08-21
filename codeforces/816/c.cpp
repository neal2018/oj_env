#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  map<ll, ll> mp;
  mp[0] = 0, mp[n] = n + 1;
  ll res = 0;
  auto get = [&](ll l, ll r) {
    return n * (n + 1) / 2 - (l * (l + 1) / 2) - ((n - r) * (n - r + 1) / 2);
  };
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && a[i] == a[j];) j++;
    mp[i] = a[i];
    res += get(i, j);
  }
  auto cut = [&](ll i) {
    auto it = --mp.upper_bound(i);
    auto l = it->first, r = next(it)->first;
    res += -get(l, r) + get(l, i) + get(i, r);
    mp[i] = a[i];
  };
  auto link = [&](ll i) {
    auto it = mp.find(i);
    auto l = prev(it)->first, r = next(it)->first;
    res += get(l, r) - (get(l, i) + get(i, r));
    mp.erase(it);
  };
  while (m--) {
    int i, x;
    cin >> i >> x, i--;
    if (a[i] != x) {
      if (!mp.count(i)) cut(i);
      if (i > 0 && a[i - 1] == x) link(i);
      if (!mp.count(i + 1)) cut(i + 1);
      if (i < n - 1 && a[i + 1] == x) link(i + 1);
      a[i] = x;
    }
    cout << res << "\n";
  }
}
