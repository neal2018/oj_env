#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, p, w, d;
  cin >> n >> p >> w >> d;
  ll y_max = min(p / d, (w * n - p) / (w - d));
  if (y_max < 0) {
    cout << "-1\n";
    return 0;
  }
  ll p_w = p % w, d_w = d % w;
  ll t = 0, cnt = 0, chance = -1;
  set<ll> seen;
  while (seen.count(t) == 0) {
    if (t == p_w) chance = cnt;
    seen.insert(t);
    t = (t + d) % w;
    cnt++;
  }
  if (chance == -1) {
    cout << "-1\n";
    return 0;
  }
  ll y = chance;
  if (y <= y_max) {
    ll x = (p - y * d) / w;
    cout << x << " " << y << " " << n - x - y << "\n";
  } else {
    cout << "-1\n";
  }
}
