#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, target;
  cin >> n >> target;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  // reverse(a.begin(), a.end());
  map<ll, ll> mp;
  function<ll(ll, ll)> dfs = [&](ll m, ll i) {
    if (mp.count(m)) return mp[m];
    assert(m % a[i] == 0);
    ll res = m / a[i];
    if (i < n - 1) {
      ll remain = m % a[i + 1];
      res = min(res, dfs(m - remain, i + 1) + remain / a[i]);
      ll extra = a[i + 1] - remain;
      res = min(res, dfs(m + extra, i + 1) + extra / a[i]);
    }
    return mp[m] = res;
  };
  cout << dfs(target, 0) << '\n';
}
