#include <bits/stdc++.h>
using namespace std;

#define FOR(x, n) for (int x = 0; x < n; x++)
#define PI 3.14159265358979323846264338327950288
typedef long long ll;
typedef long long ii;

constexpr int MAXN = 2e5 + 20;
constexpr int SQ = 400;
constexpr ll MOD1 = 1000002193;
constexpr int PSTR = 31;

int STRPOW1[MAXN];
unordered_map<int, vector<int>> positions;

constexpr ll mod_exp(ll x, ll y, ll mod) {
  ll res = 1;
  while (y > 0) {
    if (y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}

constexpr int PINV1 = mod_exp(PSTR, MOD1 - 2, MOD1);

void pre(const string& s) {
  int n = s.length();

  STRPOW1[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    STRPOW1[i] = (1ll * PSTR * STRPOW1[i - 1]) % MOD1;
  }

  for (int i = 1; i <= min((int)s.length(), SQ); i++) {
    ii h = 0;
    FOR(j, i) { h = (h + (ll)(s[j] - 'a') * STRPOW1[j]) % MOD1; }
    //positions[h].push_back(0);
    for (int j = i; j < n; j++) {
      h -= (s[j - i] - 'a');
      if (h < 0) h += MOD1;
      h = (h * PINV1) % MOD1;
      h = (h + (ll)(s[j] - 'a') * STRPOW1[i - 1]) % MOD1;
      //positions[h].push_back(j - i + 1);
    }
  }
}

ii hsh(const string& s) {
  const int k = s.length();
  ii h = 0;
  FOR(j, k) { h = (h + (ll)(s[j] - 'a') * STRPOW1[j]) % MOD1; }
  return h;
}

int find(const string& s, ii look, int i, int k) {
  ii h = 0;
  int n = s.length();
  FOR(j, i) { h = (h + (ll)(s[j] - 'a') * STRPOW1[j]) % MOD1; }
  int ct = 0;
  if (h == look) {
    if (ct == k) return 0;
    ct++;
  }
  for (int j = i; j < n; j++) {
    h -= (s[j - i] - 'a');
    if (h < 0) h += MOD1;
    h = (h * PINV1) % MOD1;
    h = (h + (ll)(s[j] - 'a') * STRPOW1[i - 1]) % MOD1;
    if (h == look) {
      if (ct == k) return j - i + 1;
      ct++;
    }
  }
  return -2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  positions.reserve(4096);
  string s;
  cin >> s;

  pre(s);
  int q;
  cin >> q;
  string w;
  int k;
  // while (q--) {
  //   cin >> w >> k;
  //   k--;
  //   ii h = hsh(w);
  //   if (w.length() <= SQ) {
  //     if (k >= (int)positions[h].size())
  //       cout << "-1\n";
  //     else
  //       cout << positions[h][k] + 1 << '\n';
  //   } else {
  //     cout << find(s, h, w.length(), k) + 1 << '\n';
  //   }
  // }
}