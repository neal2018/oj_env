#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;

namespace io {
constexpr int SIZE = 1 << 16;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
template <typename T>
T read() {
  T x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}
string read_s() {
  string str;
  char c = get_char();
  while (c == ' ' || c == '\n' || c == '\r') c = get_char();
  while (c != ' ' && c != '\n' && c != '\r') str += c, c = get_char();
  return str;
}
void print(auto x) {
  if (x > 9) print(x / 10);
  putchar(int(x % 10) | '0');
}
void println(auto x) { print(x), putchar('\n'); }
struct Read {
  Read& operator>>(int& x) { return x = read<int>(), *this; }
  Read& operator>>(ll& x) { return x = read<ll>(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
  Read& operator>>(string& x) { return x = read_s(), *this; }
} in;
}  // namespace io

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
  // cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, m;
    cin >> n >> m;
    ll nm_1 = n * m - 1;
    ll phi = nm_1;
    while (nm_1 != 1) {
      auto t = get_max_factor(nm_1);
      phi = phi / t * (t - 1);
      while (nm_1 % t == 0) nm_1 /= t;
    }
    ll res = phi;
    vector<pair<ll, ll>> a;
    while (phi != 1) {
      auto t = get_max_factor(phi);
      ll cnt = 0;
      while (phi % t == 0) phi /= t, cnt++;
      a.push_back({t, cnt});
    }
    function<void(ll, ll)> dfs = [&](ll i, ll cur) {
      if (i == a.size()) {
        auto t = power(n, cur, n * m - 1);
        // cout << cur << ' ';
        // io::println(t);
        if (t == 1) {
          res = min(res, cur);
        }
        return;
      }
      for (ll j = 0; j <= a[i].second; j++) {
        dfs(i + 1, cur);
        cur *= a[i].first;
      }
    };
    dfs(0, 1);
    cout << res << '\n';
  }
}
