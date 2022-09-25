#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n;
  cin >> n;
  vector<ll> res;
  for (ll t = n; t >= 0; t = n & (t - 1)) {
    res.push_back(t);
    if (t == 0) break;
  }
  sort(res.begin(), res.end());
  for (auto& x : res) cout << x << "\n";
}
