#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll H = 320;
constexpr ll MAX = 1e5 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  ll res = n - 1;
  vector<ll> t(n);
  for (ll d = -H; d < H; d++) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
      t[cnt++] = a[i] - d * i;
    }
    sort(t.begin(), t.begin() + cnt);
    for (int i = 0, j; i < cnt; i = j) {
      for (j = i; j < cnt && t[i] == t[j];) j++;
      res = min(res, n - (j - i));
    }
  }
  for (int ii = 0; ii < n; ii++) {
    ll cnt = 0;
    for (int jj = ii + 1; jj < n && jj - ii < H; jj++) {
      if ((a[jj] - a[ii]) % (jj - ii)) continue;
      t[cnt++] = (a[jj] - a[ii]) / (jj - ii);
    }
    sort(t.begin(), t.begin() + cnt);
    for (int i = 0, j; i < cnt; i = j) {
      for (j = i; j < cnt && t[i] == t[j];) j++;
      res = min(res, n - (j - i + 1));
    }
  }
  cout << res << "\n";
}
