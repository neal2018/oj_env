#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

using Hash = pair<ull, ull>;

constexpr Hash mod = {1000000069, 1000000067};

Hash operator*(const Hash &a, const Hash &b) {
  return {a.first * b.first % mod.first, a.second * b.second % mod.second};
}

Hash operator+(const Hash &a, const Hash &b) {
  return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}

Hash operator-(const Hash &a, const Hash &b) {
  return {(a.first - b.first + mod.first) % mod.first,
          (a.second - b.second + mod.second) % mod.second};
}

Hash operator*(const Hash &a, const ull &b) {
  return {a.first * b % mod.first, a.second * b % mod.second};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    Hash base = {rng() % 1000, rng() % 1000};
    vector<Hash> hash(n + 1);
    hash[0] = {1, 1};
    for (int i = 1; i <= n; i++) hash[i] = hash[i - 1] * base;
    Hash cur{0, 0};
    for (int i = 2; i < n; i++) cur = cur + hash[i - 2] * (s[i] - 'a');
    set<Hash> st{cur};
    for (int i = 0; i < n - 2; i++) {
      cur = cur + hash[i] * (s[i] - 'a');
      if (i + 2 < n) cur = cur - hash[i] * (s[i + 2] - 'a');
      st.insert(cur);
    }
    cout << st.size() << "\n";
  }
}
