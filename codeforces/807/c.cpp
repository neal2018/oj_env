#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, c, q;
    string s;
    cin >> n >> c >> q >> s;
    vector<pair<ll, ll>> a{{0, n}};
    while (c--) {
      ll l, r;
      cin >> l >> r, l--;
      a.push_back({l, r});
    }
    vector<ll> pre(a.size());
    for (int i = 1; i < a.size(); i++) {
      pre[i] = pre[i - 1] + a[i - 1].second - a[i - 1].first;
    }
    function<char(ll)> get = [&](ll x) {
      auto i = int(--upper_bound(pre.begin(), pre.end(), x) - pre.begin());
      if (i == 0) {
        return s[x];
      } else {
        ll offset = x - pre[i];
        return get(a[i].first + offset);
      }
    };
    while (q--) {
      ll k;
      cin >> k;
      k--;
      cout << get(k) << "\n";
    }
  }
}
