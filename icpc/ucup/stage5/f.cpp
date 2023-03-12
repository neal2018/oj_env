#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int MOD = 998244353;
int power(int, ll) = delete;
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s >> MOD;
  constexpr int MAX = 94, BASE = 33;
  // constexpr int MAX = 3, BASE = 'a';
  vector<Z> one(MAX);
  vector two(MAX, vector<Z>(MAX));
  string rev(s.rbegin(), s.rend());
  for (auto &c : rev) {
    int cur = c - BASE;
    for (int i = 0; i < MAX; i++) {
      two[i][cur] += one[i];
    }
    one[cur] += 1;
  }
  Z res = 0;
  Z sum_pair = 0;
  vector<Z> one_pos(MAX);
  vector two_pos(MAX, vector<Z>(MAX));
  for (auto &c : s) {
    int cur = c - BASE;
    one[cur] -= 1;
    for (int i = 0; i < MAX; i++) {
      two[i][cur] -= one[i];
      sum_pair -= one[i] * two_pos[i][cur];
    }
    // cout << sum_pair << "\n";
    res += sum_pair;
    for (int i = 0; i < MAX; i++) {
      two_pos[i][cur] += one_pos[i];
      sum_pair += two[i][cur] * one_pos[i];
    }
    one_pos[cur] += 1;
  }
  cout << res << "\n";
}
