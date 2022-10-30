#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

i128 power(i128 a, i128 b, i128 MOD = 1, i128 res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}

bool is_prime(ll n) {
  if (n < 2) return false;
  static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  int s = __builtin_ctzll(n - 1);
  ll d = (n - 1) >> s;
  for (auto a : A) {
    if (a == n) return true;
    ll x = (ll)power(a, d, n);
    if (x == 1 || x == n - 1) continue;
    bool ok = false;
    for (int i = 0; i < s - 1; ++i) {
      x = ll((i128)x * x % n);  // potential overflow!
      if (x == n - 1) {
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}

ll pollard_rho(ll x) {
  ll s = 0, t = 0, c = rng() % (x - 1) + 1;
  ll stp = 0, goal = 1, val = 1;
  for (goal = 1;; goal *= 2, s = t, val = 1) {
    for (stp = 1; stp <= goal; ++stp) {
      t = ll(((i128)t * t + c) % x);
      val = ll((i128)val * abs(t - s) % x);
      if ((stp % 127) == 0) {
        ll d = gcd(val, x);
        if (d > 1) return d;
      }
    }
    ll d = gcd(val, x);
    if (d > 1) return d;
  }
}

ll get_max_factor(ll _x) {
  ll max_factor = 0;
  function<void(ll)> fac = [&](ll x) {
    if (x <= max_factor || x < 2) return;
    if (is_prime(x)) {
      max_factor = max_factor > x ? max_factor : x;
      return;
    }
    ll p = x;
    while (p >= x) p = pollard_rho(x);
    while ((x % p) == 0) x /= p;
    fac(x), fac(p);
  };
  fac(_x);
  return max_factor;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  cin >> m >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<pair<int, int>>> g(m);
  for (int i = 0; i < k; i++) {
    int u, v, d;
    cin >> u >> v >> d, u--, v--;
    g[u].push_back({v, d});
  }
  vector<ll> res(m);
  for (int i = m - 1; i >= 0; i--) {
    auto t = g[i][0].first;
    auto f = get_max_factor(a[t]);
    res[i] = f;
    for (auto [ne, d] : g[i]) {
      while (d--) {
        a[ne] /= f;
      }
    }
  }
  for (auto& x : res) cout << x << " ";
}
