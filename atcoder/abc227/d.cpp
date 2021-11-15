#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  auto check = [&](ll mid) {
    ll c = 0;
    for (auto& x : a) c += min(x, mid);
    return c >= mid * k;
  };
  ll l = 0, r = accumulate(a.begin(), a.end(), 0ll) / k + 1;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << '\n';
}