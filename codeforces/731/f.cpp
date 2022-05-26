#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

namespace io {
constexpr int SIZE = 1e6 + 10;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
int read() {
  int x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}
struct Read {
  Read& operator>>(int& x) { return x = read(), *this; }
} in;
}  // namespace io
int GCD(int a, int b) {
  while (b && (b ^= a ^= b ^= a %= b))
    ;
  return a;
}
#define __gcd GCD
struct SegTree {
  int n;
  vector<int> t;
  SegTree(int _n) : n(_n), t(2 * n){};
  void modify(int p, const int& v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = __gcd(t[p * 2], t[p * 2 + 1]);
  }
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res = __gcd(t[l++], res);
      if (r & 1) res = __gcd(t[--r], res);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, g = 0;
  io::in >> n;
  vector<int> a(n);
  for (auto& x : a) io::in >> x, g = __gcd(g, x);
  int t = n;
  // while (t < n) t *= 2;
  SegTree seg(t);
  for (int i = 0; i < n; i++) seg.t[i + t] = a[i] / g;
  for (int i = t - 1; i; i--) seg.t[i] = __gcd(seg.t[i * 2], seg.t[i * 2 + 1]);
  auto query_cross = [&](int l, int r) {
    if (l >= 0) {
      return seg.query(l, r + 1);
    } else {
      return __gcd(seg.query(0, r + 1), seg.query(l + n, n));
    }
  };

  int res = 0, l = -(n - 1);
  for (int i = 0; i < n; i++) {
    while (query_cross(l, i) == 1 && l <= i) {
      l++;
    }
    res = max(res, i - l + 1);
  }
  cout << res << "\n";
}
