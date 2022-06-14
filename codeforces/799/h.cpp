#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, vector<int>> mp;
    for (int i = 0; auto& x : a) cin >> x,mp[x].push_back(i++);
    ll res = -1, val = 0, r = 0, l = 0;
    for (auto& [k, v] : mp) {
      int cur = 0, pre = v[0];
      for (int i = 0; i < v.size(); i++) {
        cur = cur + (i > 0 ? (v[i - 1] - v[i] + 1) : 0) + 1;
        if (cur > res) res = cur, l = pre, r = v[i], val = k;
        if (cur < 1) pre = v[i], cur = 1;
      }
    }
    cout << val << " " << l + 1 << " " << r + 1 << "\n";
  }
}
