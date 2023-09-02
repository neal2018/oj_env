#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  map<ll, vector<ll>> occ;
  for (int i = 0; i < n; i++) {
    occ[a[i]].push_back(i);
  }
  ll res = 0;
  for (auto& [k, v] : occ) {
    ll cur = 0;
    for (ll i = 0; i < v.size(); i++) {
      cur += i * (v[i] - i) - (v.size() - i - 1) * (v[i] - i);
    }
    res += cur;
  }
  cout << res << "\n";
}
