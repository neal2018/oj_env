#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll maxi = *max_element(a.begin(), a.end());
}
