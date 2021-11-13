#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q, diff;
  cin >> n;
  int a[n];
  for (auto& x : a) cin >> x;
  for (int i = 0, x; i < n; i++) cin >> x, a[i] -= x;
  vector<int> mu(n + 1), min_primes(n + 1), primes;
  diff = a[0], a[0] = 0, mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!min_primes[i]) min_primes[i] = i, mu[i] = -1, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i > n) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
      mu[p * i] = -mu[i];
    }
  }
  vector<int> f;
  ll res = 0;
  for (int i = 1; i <= n; i++) {
    if (!mu[i]) {
      res += abs(a[i - 1]);
    } else {
      f.push_back(a[i - 1] * mu[i]);
    }
    for (int j = i * 2; j <= n; j += i) a[j - 1] -= a[i - 1];
  }
  ranges::sort(f);
  int sz = (int)f.size();
  vector<ll> pre(sz + 1);
  for (int i = 0; i < sz; i++) pre[i + 1] = pre[i] + f[i];
  cin >> q;
  for (int x; q--;) {
    cin >> x;
    x = diff - 1 - x;
    ll pos = ranges::upper_bound(f, -x) - f.begin();
    ll addon = ((sz - pos) * x + pre[sz] - pre[pos]) - (pos * x + pre[pos]);
    cout << res + addon << '\n';
  }
}