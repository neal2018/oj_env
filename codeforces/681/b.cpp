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
  auto operator<=>(const Z &) const = default;  // need c++ 20
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
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pos(n);
    for (int i = 0; auto &x : a) cin >> x, x--, pos[x] = i++;
    vector<bool> seen(n);
    vector<int> b(k);
    for (auto &x : b) {
      cin >> x, x--;
      x = pos[x];
      seen[x] = true;
    }
    set<int> s{-1, n};
    for (int i = 0; i < n; ++i) s.insert(i);
    Z res = 1;
    for (int i = 0; i < k; ++i) {
      auto it = s.find(b[i]);
      int l = *prev(it), r = *next(it);
      bool gl = l >= 0 && !seen[l];
      bool gr = r < n && !seen[r];
      if (!gl && !gr) {
        res = 0;
        break;
      } else if (gl && gr) {
        res *= 2;
        s.erase(l);
      } else if (gl) {
        s.erase(l);
      } else {
        s.erase(r);
      }

      seen[b[i]] = false;
    }
    cout << res << "\n";
  }

  return 0;
}
