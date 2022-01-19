#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, res = 0, d, done = -1;
  cin >> n >> d;
  vector<pair<ll, ll>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  sort(a.begin(), a.end(), [](auto x, auto y) { return x.second < y.second; });
  for (auto& [x, y] : a) {
    if (x > done) res++, done = y + d - 1;
  }
  cout << res << "\n";
}