#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  k -= l, r -= l;
  if (x > y) {
    if (k + y <= r) k += y;
    k -= x;
    if (k < 0) return cout << "No\n", 0;
    if (t <= k / (x - y) + 1) {
      return cout << "Yes\n", 0;
    } else {
      return cout << "No\n", 0;
    }
  }
  set<ll> st;
  while (true) {
    t -= k / x, k %= x;
    if (t <= 0 || st.count(k)) return cout << "Yes\n", 0;
    st.insert(k), k += y;
    if (k > r || k < x) return cout << "No\n", 0;
  }
  return 0;
}