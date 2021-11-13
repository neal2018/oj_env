#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> p(n);
  for (auto& [a, c] : p) cin >> a >> c;
  sort(p.begin(), p.end());
  ll cost = 0, maxi = p[0].first + p[0].second;
  for (auto& [a, c] : p) cost += max(c, a + c - maxi), maxi = max(maxi, a + c);
  cout << cost << '\n';
}




