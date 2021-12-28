#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k, res = 0, sum = 0;
  cin >> n >> k;
  map<ll, ll> mp = {{0, 1}};
  for (ll i = 0, x; i < n; i++) {
    cin >> x;
    sum += x;
    res += mp[sum - k], mp[sum]++;
  }
  cout << res << "\n";
}