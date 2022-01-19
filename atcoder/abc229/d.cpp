#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  ll n = s.size(), k;
  cin >> k;
  vector<ll> pre(n + 1);
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (s[i] == '.');
  auto check = [&](ll mid) {
    for (int i = 0; i + mid <= n; i++) {
      ll cnt = pre[i + mid] - pre[i];
      if (cnt <= k) return true;
    }
    return false;
  };
  ll l = 0, r = n;
  while (l < r) {
    ll mid = (l + r + 1) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << "\n";
}