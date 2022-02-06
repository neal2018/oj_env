#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll P, l0, r0, L, R;
  cin >> P >> l0 >> r0 >> L >> R;
  if (P < 0) {
    P = -P;
    swap(l0, r0);
    l0 = -l0, r0 = -r0;
  }
  if (L < 0 && R <= 0) {
    swap(L, R);
    L = -L, R = -R;
  }
  auto get = [&](ll RR) {  // [0, )
    ll res = 0;
    for (ll l = 1, r; l <= P; l = r + 1) {
      r = P / (P / l);
      ll c = P / l;
      ll left = max(l, (P - r0 + c - 1) / c);
      ll right = min({RR, r + 1, (P - l0) / c + 1});
      res += max(0ll, right - left);
    }
    if (P >= l0 && P <= r0) {
      res += max(0ll, RR - P - 1);
    }
    // cout << RR << " " << res << "\n";
    return res;
  };
  ll ans = get(R + 1);
  if (L < 0) {
    ans += get(-L + 1);
  } else {
    ans -= get(L);
  }
  cout << ans << "\n";
}