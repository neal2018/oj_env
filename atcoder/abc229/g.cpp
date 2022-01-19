#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 10;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  ll k, n = s.size();
  cin >> k;
  vector<ll> p;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'Y') p.push_back(i);
  }
  ll sz = p.size();
  for (int i = 0; i < sz; i++) p[i] -= i;
  vector<ll> pre(sz + 1);
  for (int i = 0; i < sz; i++) pre[i + 1] = pre[i] + p[i];
  auto check = [&](ll mid) {
    for (int i = 0; i + mid <= sz; i++) {
      ll left = pre[i + mid / 2] - pre[i], right = pre[i + mid] - pre[i + (mid + 1) / 2];
      if (right - left <= k) return true;
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