#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> b(n), mark(n);
  for (auto& x : b) cin >> x;
  ll sum = 0, cnt = 0, res = 0;
  for (ll i = n - 1; i >= 0; i--) {
    sum -= cnt;
    if (mark[i]) cnt -= mark[i];
    ll cur = (i < k ? i + 1 : k);
    ll add = max(0ll, (b[i] - sum + cur - 1) / cur);
    cnt += add, sum += add * cur, res += add;
    mark[max(0ll, i - k)] += add;
  }
  cout << res << "\n";
}
