#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

using Hash = pair<ll, ll>;

constexpr Hash mod = {1000000033, 1000000087};

Hash operator*(const Hash &a, const Hash &b) {
  return {a.first * b.first % mod.first, a.second * b.second % mod.second};
}

Hash operator+(const Hash &a, const Hash &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}

Hash operator*(const Hash &a, const ll &b) {
  return {a.first * b % mod.first, a.second * b % mod.second};
}

Hash operator^(const Hash &a, const Hash &b) { return {a.first ^ b.first, a.second ^ b.second}; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  map<ll, Hash> hash;
  vector<Hash> hash_a(n), hash_b(n);
  {
    set<ll> st;
    Hash cur = {0, 0};
    for (ll i = 0; i < n; i++) {
      if (hash.count(a[i]) == 0) {
        hash[a[i]] = {rng(), rng()};
      }
      if (st.count(a[i]) == 0) {
        st.insert(a[i]), cur = cur ^ hash[a[i]];
      }
      hash_a[i] = cur;
    }
  }
  {
    set<ll> st;
    Hash cur = {0, 0};
    for (ll i = 0; i < n; i++) {
      if (hash.count(b[i]) == 0) {
        hash[b[i]] = {rng(), rng()};
      }
      if (st.count(b[i]) == 0) {
        st.insert(b[i]), cur = cur ^ hash[b[i]];
      }
      hash_b[i] = cur;
    }
  }
  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r, l--, r--;
    cout << (hash_a[l] == hash_b[r] ? "Yes\n" : "No\n");
  }
}
