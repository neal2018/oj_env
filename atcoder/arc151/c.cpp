#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> a{{0, -1}};
  for (int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  a.push_back({n + 1, -1});
  auto sg = [&](ll n, ll s, ll e) -> ll {
    if (s == -1 && e == -1) return n % 2;
    if (s == -1 || e == -1) return n;
    return s == e;
  };
  ll res = 0;
  for (int i = 1; i < a.size(); i++) {
    auto [x1, y1] = a[i - 1];
    auto [x2, y2] = a[i];
    auto t = sg(x2 - x1 - 1, y1, y2);
    res ^= t;
  }
  cout << (res ? "Takahashi\n" : "Aoki\n");
}
