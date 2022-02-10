#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094
constexpr ll MOD = 998244353;

ll norm(ll x) { return (x + MOD) % MOD; }
template <class T>
T power(T a, ll b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  ll x;
  Z(ll _x = 0) : x(norm(_x)) {}
  // auto operator<=>(const Z &) const = default;
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2); }
  Z &operator*=(const Z &rhs) { return x = x * rhs.x % MOD, *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

struct Node {
  ll maxi = 0, len = 0;
  Z a[3][3] = {};
  Node() {
    for (int i = 0; i < 3; i++) a[i][i] = 1;
  }
  Node(int x) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == x) {
          a[i][j] = (j == x ? 1 : (MOD + 1) / 2);
        } else {
          a[i][j] = (j == i ? (MOD + 1) / 2 : 0);
        }
      }
    }
  }
};

Node pull(const Node &a, const Node &b) {
  Node c;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      c.a[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        c.a[i][j] += b.a[i][k] * a.a[k][j];
      }
    }
  }
  return c;
}

struct SegTree {
  ll n;
  vector<Node> t;
  SegTree(ll _n) : n(_n), t(2 * n){};
  void modify(ll p, const Node &v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(ll l, ll r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, q;
  string s;
  cin >> n >> q >> s;

  SegTree seg(n);
  for (int i = 0; i < n; i++) {
    seg.modify(i, Node(s[i] - '1'));
  }
  while (q--) {
    int op, x, y;
    cin >> op >> x >> y, x--;
    if (op == 1) {
      seg.modify(x, Node(y - 1));
    } else {
      auto node = seg.query(x, y);
      for (int i = 0; i < 3; i++) {
        Z res = 0;
        for (int j = 0; j < 3; j++) {
          res += node.a[i][j];
        }
        cout << res << " ";
      }
      cout << "\n";
    }
  }
}
