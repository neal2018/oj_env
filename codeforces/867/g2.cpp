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
  auto fac = [&](auto&& self, ll x) {
    if (x <= max_factor || x < 2) return;
    if (is_prime(x)) {
      max_factor = max_factor > x ? max_factor : x;
      return;
    }
    ll p = x;
    while (p >= x) p = pollard_rho(x);
    while ((x % p) == 0) x /= p;
    self(self, x), self(self, p);
  };
  fac(fac, _x);
  return max_factor;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  unordered_map<ll, vector<ll>> mp;
  mp.reserve(1023);
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    unordered_map<ll, ll> freq;
    freq.reserve(2047);
    for (auto& x : a) freq[x]++;
    a.erase(unique(a.begin(), a.end()), a.end());
    ll res = 0;
    for (auto& k : a) {
      auto v = freq[k];
      res += v * (v - 1) * (v - 2);
      if (mp.count(k) == 0) {
        vector<array<ll, 2>> factors;
        factors.reserve(3000);
        auto phi = k;
        while (phi != 1) {
          auto t = get_max_factor(phi);
          ll cnt = 0;
          while (phi % t == 0) phi /= t, cnt++;
          if (cnt > 1) {
            factors.push_back({t, cnt / 2});
          }
        }
        vector<ll> goods;
        goods.reserve(3000);
        auto dfs = [&](auto&& self, int i, ll cur) {
          if (i == factors.size()) {
            goods.push_back(cur);
            return;
          }
          for (int ii = 0; ii <= factors[i][1]; ii++) {
            self(self, i + 1, cur), cur *= factors[i][0];
          }
        };
        dfs(dfs, 0, 1);
        mp[k] = goods;
      }
      for (auto i : mp[k]) {
        if (i == 1) continue;
        res += v * freq[k / i] * freq[k / i / i];
      }
    }
    cout << res << "\n";
  }
}
