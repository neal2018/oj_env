#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr ll N = 1e6 + 10;
  vector<int> min_primes(N + 1), primes;
  primes.reserve(1e5);
  for (int i = 2; i <= N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (i * p > N) break;
      min_primes[i * p] = p;
      if (i % p == 0) break;
    }
  }
  auto check = [&](ll x) { return x > 1 && min_primes[x] == x; };
  ll T;
  cin >> T;
  for (int n, e; T--;) {
    cin >> n >> e;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector<ll> pre(n), post(n);
    for (int i = 0; i < n; i++) {
      pre[i] = (a[i] == 1);
      if (i >= e && pre[i] == 1) pre[i] += pre[i - e];
    }
    for (int i = n - 1; i >= 0; i--) {
      post[i] = (a[i] == 1);
      if (i < n - e && post[i] == 1) post[i] += post[i + e];
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
      if (check(a[i])) {
        ll before = 1, after = 1;
        if (i >= e) before += pre[i - e];
        if (i < n - e) after += post[i + e];
        res += before * after - 1;
      }
    }
    cout << res << '\n';
  }
}