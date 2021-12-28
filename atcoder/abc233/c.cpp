#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, a, res = 0;
  cin >> n >> a;
  vector<vector<ll>> l(n);
  for (ll i = 0, x; i < n; i++) {
    cin >> x;
    for (ll j = 0, t; j < x; j++) {
      cin >> t;
      l[i].push_back(t);
    }
  }
  function<void(ll, ll)> dfs = [&](ll node, ll cur) {
    if (node == n) {
      if (cur == a) res++;
      return;
    }
    for (auto x : l[node]) {
      if ((__int128)(cur * x) <= a) dfs(node + 1, cur * x);
    }
  };
  dfs(0, 1);
  cout << res << "\n";
}