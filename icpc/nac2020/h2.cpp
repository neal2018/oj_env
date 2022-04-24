#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
const char nl = '\n';

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

using Hash = pair<ll, ll>;
Hash mod = {1000000069, 1000000067};

Hash operator*(const Hash& a, const Hash& b) {
  return {(a.first * b.first % mod.first + mod.first) % mod.first,
          (a.second * b.second % mod.second + mod.second) % mod.second};
}

Hash operator+(const Hash& a, const Hash& b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}

Hash operator-(const Hash& a, const Hash& b) {
  return {(a.first - b.first + 10 * mod.first) % mod.first,
          (a.second - b.second + 10 * mod.second) % mod.second};
}
Hash operator*(const Hash& a, ll b) {
  // cout<<a.first<<" "<<a.second<<"\n";
  // cout<<b<<"\n";
  // cout<<mod.first<<" "<<mod.second<<"\n\n";
  // cout<<((-1) %1000000069)<<"\n";
  // cout<<((-1) % mod.first + mod.first)<<"\n";
  return {((a.first * b) % mod.first + mod.first) % mod.first,
          ((a.second * b) % mod.second + mod.second) % mod.second};
}

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  string aa, bb, cc;
  cin >> aa >> bb >> cc;
  ll n = aa.size();
  ll base = 5;
  vector<Hash> hash(n + 1);
  hash[0] = {1, 1};
  for (int i = 0; i < n; i++) hash[i + 1] = hash[i] * base;
  // for (auto& x : hash) cout << x.first << " " << x.second << "\n";
  auto get_val = [&](char c) {
    if (c == 'A') {
      return 1;
    } else if (c == 'B') {
      return 2;
    }
    return -3;
  };
  auto get_hash = [&](string& s) {
    Hash h = {0, 0};
    for (int i = 0; i < n; i++) {
      ll cur = get_val(s[i]);
      h = h + hash[n - 1 - i] * cur;
    }
    return h;
  };
  // auto tt = hash[0]*(-1);
  // cout<<tt.first<<" "<<tt.second<<"\n";
  Hash hash_a = get_hash(aa);
  Hash hash_b = get_hash(bb);
  Hash hash_c = get_hash(cc);
  // cout << hash_a.first << " " << hash_a.second << "\n";
  // cout << hash_b.first << " " << hash_b.second << "\n";
  // cout << hash_c.first << " " << hash_c.second << "\n";
  // auto t = hash_a + hash_b + hash_c;
  // cout << t.first << " " << t.second << "\n";
  ll res = inf;
  auto solve = [&](string& sa, string& sb, string& sc, Hash a, Hash b, Hash c) {
    for (ll i = 0; i < n; i++) {
      auto temp_c = c;
      for (ll j = 0; j < n; j++) {
        // cout << a.first << " " << a.second << " " << b.first << " " << b.second << " " <<
        // temp_c.first
        //      << " " << temp_c.second << "\n";
        // auto t = a + b + cc;
        if (a + b + temp_c == Hash{0, 0}) {
          res = min(res, i + j - min(i, j));
          res = min(res, n - i + n - j - min(n - i, n - j));
          res = min(res, i + n - j);
          res = min(res, n - i + j);
        }
        temp_c = (temp_c - hash[n - 1] * get_val(sc[j])) * base + hash[0] * +get_val(sc[j]);
      }
      b = (b - hash[n - 1] * get_val(sb[i])) * base + hash[0] * +get_val(sb[i]);
    }
  };
  solve(aa, bb, cc, hash_a, hash_b, hash_c);
  // solve(bb, aa, cc, hash_b, hash_a, hash_c);
  // solve(cc, bb, aa, hash_c, hash_b, hash_a);
  cout << (res == inf ? -1 : res) << "\n";
}