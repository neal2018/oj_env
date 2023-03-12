#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

using Hash = __uint128_t;
struct StringHash {
  int n;
  vector<Hash> power, rev, hashes;
  mt19937_64 rng = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
  Hash base = 30, MOD = 9223372036737335297;
  StringHash(const string &s)
      : n(s.size()), power(n + 1, 1), rev(n + 1, 1), hashes(n + 1), base(rng() % 1000 + 50) {
    for (int i = 1; i <= n; i++) power[i] = power[i - 1] * base % MOD;
    rev[n] = power_fn(power[n], MOD - 2);
    for (int i = n - 1; i > 0; i--) rev[i] = rev[i + 1] * base % MOD;
    for (int i = 0; i < n; i++) hashes[i + 1] = (hashes[i] + (s[i] - 'a') * power[i]) % MOD;
  }
  Hash power_fn(Hash a, Hash b, Hash res = 1) {
    for (; b; b /= 2, (a *= a) %= MOD)
      if (b & 1) (res *= a) %= MOD;
    return res;
  }
  Hash get_hash(int start, int end) {
    if (end <= start) return 0;
    return (hashes[end] - hashes[start] + MOD) * rev[start] % MOD;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    StringHash sh(s);
    set<Hash> st;
    for (int i = 0; i < n - 1; i++) {
      auto first = sh.get_hash(0, i);
      auto second = sh.get_hash(i + 2, n);
      auto cur = (first + second * sh.power[i]) % sh.MOD;
      st.insert(cur);
    }
    cout << st.size() << "\n";
  }
}
