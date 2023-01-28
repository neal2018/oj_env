#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MOD = 998244353;
template <typename T>
T power(T a, ll b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  // auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(ll(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

int max_suffix(string_view s) {
  int i = 0, j = 1, k = 0, n = int(s.size());
  while (i + k < n && j + k < n) {
    if (s[i + k] == s[j + k]) {
      k += 1;
    } else {
      if (s[i + k] < s[j + k]) {
        i += k + 1;
      } else {
        j += k + 1;
      }
      if (i == j) i += 1;
      k = 0;
    }
  }
  return min(i, j);
}

auto duval(string s) {
  s += 'a' - 1;
  int n = (int)s.size();
  vector<pair<string, int>> t;
  for (int i = 0; i < n;) {
    int j = i, k = i + 1, cnt = 0;
    for (; k < n && s[j] >= s[k]; j++, k++) {
      if (s[j] > s[k]) j = i - 1;
    }
    t.push_back({s.substr(i, k - j), 0});
    while (i <= j) cnt++, i += k - j;
    t.back().second = cnt;
  }
  return t;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  int k;
  cin >> s >> k;
  for (int _ = 0; _ < k; _++) {
    int t = max_suffix(s);
    int n = int(s.size());
    cout << s << "\n";
    cout << t << "\n";
    auto tt = duval(s);
    for (int i = t; i < n; i++) {
      s += s[i];
      cout << s[i];
    }
    cout << "\n";
    for (auto &[x, cnt] : tt)
      while (cnt--) cout << x << "\n";
    cout << "\n";
  }
  array<Z, 26> a = {};
  for (auto &c : s) a[c - 'a'] += 1;
  for (int i = 0; i < 26; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}