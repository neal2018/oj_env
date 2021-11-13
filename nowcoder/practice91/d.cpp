#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n][3];
  long long cum = 0, pre_sum = 0, v[n], suffix[n], cnt = 0;
  for (int i = 0; i < n; i++) cin >> a[i][0];
  for (int i = 0; i < n; i++) cin >> a[i][1];
  for (int i = 0; i < n; i++) cin >> a[i][2];
  suffix[n - 1] = a[n - 1][2];
  for (int i = n - 2; i >= 0; i--) suffix[i] = suffix[i + 1] + a[i][2];
  for (int i = 0; i < n; i++) {
    cum += a[i][1], pre_sum += a[i][0];
    v[i] = pre_sum + a[i][1] - cum;
  }
  map<long long, int> mp;
  sort(v, v + n);
  for (int i = 0; i < n; i++) mp[v[i]] = i;
  auto get = [&](long long x) { return lower_bound(v, v + n, x) - v; };
  vector<int> t(2 * n);
  auto query = [&](int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  };
  auto modify = [&](int p, int x) {
    t[p += n] += x;
    for (p /= 2; p > 0; p /= 2) t[p] = t[p * 2] + t[p * 2 + 1];
  };
  cum = 0, pre_sum = 0;
  for (int i = 0; i < n; i++) {
    cum += a[i][1], pre_sum += a[i][0];
    modify(mp[pre_sum + a[i][1] - cum], 1);
    (cnt += query((int)get(-suffix[i] - cum), n)) %= MOD;
  }
  cout << cnt << '\n';
}