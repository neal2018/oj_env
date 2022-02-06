#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll P, l, r, L, R;
  cin >> P >> l >> r >> L >> R;
  P = abs(P);
  r++, R++;
  ll res = 0;
  // positive
  {
    ll l0 = max(0ll, l);
    ll r0 = max(0ll, r);
    ll L0 = max(0ll, L);
    ll R0 = max(0ll, R);
    ll cur = 0;
    ll repeat = (R0 - L0) / P;
    ll once = min(r0, P) - min(l0, P);
    cur += repeat * once;
    ll remain = (R0 - L0) % P, cut = R0 - remain;
    if (remain) {
      ll really = R0 % P;
      if (really == 0) really = P;
      ll p_start = R0 - really;
      ll add = 0;
      if (p_start >= R0 - remain) {
        add += min(r0, really) - min(l0, really);
        R0 = p_start;
        p_start -= P;
      }
      add += max(0ll, min(p_start + r0, R0) - max(p_start + l0, cut));
      cur += add;
    }
    res += cur;
  }
  // negative
  {
    ll l0 = min(0ll, l);
    ll r0 = min(0ll, r);
    ll L0 = min(0ll, L);
    ll R0 = min(0ll, R);
    swap(l0, r0), swap(L0, R0);
    l0 = abs(l0), r0 = abs(r0), L0 = abs(L0), R0 = abs(R0);
    l0++, r0++, L0++, R0++;
    if (r > 0 && l <= 0) l0--;
    ll cur = 0;
    ll repeat = (R0 - L0) / P;
    ll once = min(r0, P) - min(l0, P);
    cur += repeat * once;
    ll remain = (R0 - L0) % P, cut = R0 - remain;
    if (remain) {
      ll really = R0 % P;
      if (really == 0) really = P;
      ll p_start = R0 - really;
      ll add = 0;
      if (p_start >= R0 - remain) {
        add += min(r0, really) - min(l0, really);
        R0 = p_start;
        p_start -= P;
      }
      add += max(0ll, min(p_start + r0, R0) - max(p_start + l0, cut));
      cur += add;
    }
    res += cur;
  }
  cout << res << "\n";
}