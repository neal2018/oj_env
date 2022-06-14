#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m, n--;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> lucky(m);
  for (auto& x : lucky) cin >> x;
  for (int i = n - 2; i >= 0; i--) a[i] -= a[i + 1];
  map<ll, ll> cnt;
  for (auto& x : lucky) {
    cnt[x]++;
    for (int i = n - 1, cur = 1; i >= 0; i--, cur = -cur) {
      cnt[(a[i] - x) * cur]++;
    }
  }
  ll maxi = 0;
  for (auto& [k, v] : cnt) maxi = max(maxi, v);
  cout << maxi << '\n';
}
