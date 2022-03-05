#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto f = [&]() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& x : a) cin >> x, mp[x]++;
    for (auto& [k, v] : mp) {
      if (v & 1) {
        cout << -1 << "\n";
        return;
      }
    }
    vector<pair<ll, ll>> op;
    vector<ll> res;
    for (ll i = 0; i < a.size();) {
      ll j = find(a.begin() + i + 1, a.end(), a[i]) - a.begin();
      ll len = 1;
      for (; i + len < a.size() && j + len < a.size() && a[i + len] == a[j + len];) {
        len++;
      }
      for (ll k = len; i + k < j; k++) {
        op.push_back({j + k, a[i + k]});
        a.insert(a.begin() + j + k, a[i + k]);
        a.insert(a.begin() + j + k, a[i + k]);
      }
      res.push_back((j - i) * 2);
      i = i + (j - i) * 2;
    }
    
    cout << op.size() << "\n";
    for (auto& [x, y] : op) cout << x << " " << y << "\n";
    cout << res.size() << "\n";
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  };
  while (T--) f();
}
