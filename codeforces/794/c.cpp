#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (auto& x : a) cin >> x, mp[x]++;
    sort(a.begin(), a.end());
    int f = 1;
    for (auto& [k, v] : mp) {
      if (v > n / 2) f = 0;
    }
    if ((n & 1) || !f) {
      cout << "NO\n";
      continue;
    }
    vector<ll> res(n);
    ll cur = 0;
    for (auto& x : a) {
      res[cur] = x;
      cur += 2;
      if (cur == n) cur = 1;
    }
    for (int i = 0; i < n; i++) {
      ll pre = res[(i - 1 + n) % n];
      ll nex = res[(i + 1) % n];
      if (!((pre > res[i] && res[i] < nex) || (pre < res[i] && res[i] > nex))) f = 0;
    }
    if ((n & 1) || !f) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
