#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  ll day_wo_fill = (k - l) / x;
  if (day_wo_fill >= t) {
    cout << "Yes\n";
    return 0;
  }
  ll before_1_fill = k - x * day_wo_fill;
  ll after_1_fill = before_1_fill + y;
  if (after_1_fill > r) {
    cout << "No\n";
    return 0;
  }
  t -= day_wo_fill;
  {
    k = after_1_fill;
    ll day_wo_fill = (k - l) / x;
    if (day_wo_fill >= t) {
      cout << "Yes\n";
      return 0;
    }
    ll before_1_fill = k - x * day_wo_fill;
    ll after_1_fill = before_1_fill + y;
    if (after_1_fill > r) {
      cout << "No\n";
      return 0;
    }
    ll diff =after_1_fill - k;
    if (diff > 0 && r-k <x) {
    } else if (diff < 0 && k-l) {
    } else {
      cout << "Yes\n";
      return 0;
    }
  }
}