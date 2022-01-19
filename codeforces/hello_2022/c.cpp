#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  auto ask = [&](ll i) {
    ll res;
    cout << "? " << i + 1 << endl;
    cin >> res;
    return res - 1;
  };
  while (T--) {
    cin >> n;
    ll cnt = 0;
    vector<ll> seen(n), res(n);
    for (ll i = 0; i < n; i++) {
      if (seen[i]) continue;
      vector<ll> get;
      set<ll> st;
      while (true) {
        ll x = ask(i);
        if (seen[x]) break;
        get.push_back(x);
        seen[x] = 1;
        cnt++;
      }
      ll sz = get.size();
      for (ll j = cnt % sz, tot = sz; tot >= 0; j--, tot--) {
        res[get[(j - 1 + 10 * sz) % sz]] = get[(j + 10 * sz) % sz];
      }
    }
    cout << "! ";
    for (auto& x : res) cout << x + 1 << " ";
    cout << endl;
  }
}