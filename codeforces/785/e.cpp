#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

namespace io {
constexpr int SIZE = 1 << 16;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
ll read() {
  ll x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}
string read_s() {
  string str;
  char c = get_char();
  while (c == ' ' || c == '\n' || c == '\r') c = get_char();
  while (c != ' ' && c != '\n' && c != '\r') str += c, c = get_char();
  return str;
}
void print(int x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 | '0');
}
void println(int x) { print(x), putchar('\n'); }
struct Read {
  Read& operator>>(ll& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
} in;
}  // namespace io

ll binom(ll n, ll m, ll p) { return (m > n) ? 0 : 1; }

ll lucas(ll n, ll m, ll p) {
  if (m == 0) return 1;
  return (binom(n % p, m % p, p) * lucas(n / p, m / p, p)) % p;
}

constexpr ll TWO_20 = 1ll << 20;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k;
  io::in >> n >> k;
  vector<ll> b(n);
  for (auto& x : b) io::in >> x;
  auto get_parity = [&](ll _n, ll _m) -> int { return (_n & _m) == _m; };
  string res(TWO_20, '0');
  for (int i = 0; i < n; i++) {
    __int128 val = b[i];
    for (int j = i; j < n; j++) {
      // [i, j]
      if (j != i) {
        if (b[j] >= 20) break;
        val *= (1ll << b[j]);
        if (val >= TWO_20) break;
      }
      ll cost = j - i + (i != 0) + (j != n - 1);
      ll need = k - (i != 0) - (j != n - 1);
      if (cost + need > n - 1) continue;
      if (need < 0) need = 0;
      ll total = n - (cost + 1);
      ll parity = get_parity(total - 1, need - 1);
      if (parity) res[val] = (res[val] == '1' ? '0' : '1');
    }
  }
  int f = 0;
  reverse(res.begin(), res.end());
  for (int i = 0; i < TWO_20; i++) {
    if (res[i] != '0') {
      f = 1, cout << res.substr(i);
      break;
    }
  }
  cout << (f ? "\n" : "0\n");
}
