#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace io {
constexpr int SIZE = 1 << 16;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
template <typename T>
T read() {
  T x = 0, f = 1;
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
  Read &operator>>(int &x) { return x = read<int>(), *this; }
  Read &operator>>(ll &x) { return x = read<ll>(), *this; }
  Read &operator>>(long double &x) { return x = stold(read_s()), *this; }
  Read &operator>>(string &x) { return x = read_s(), *this; }
} in;
}  // namespace io

constexpr int MOD = 998244353;

constexpr int norm(int x) {
  if (x < 0) x += MOD;
  if (x >= MOD) x -= MOD;
  return x;
}
template <typename T>
constexpr T power(T a, int b, T res = 1) {
  for (; b; b /= 2, (a *= a) %= MOD)
    if (b & 1) (res *= a) %= MOD;
  return res;
}
struct Z {
  int x;
  constexpr Z(int _x = 0) : x(norm(_x)) {}
  // constexpr auto operator<=>(const Z &) const = default; // cpp20 only
  constexpr Z operator-() const { return Z(norm(MOD - x)); }
  constexpr Z inv() const { return power(*this, MOD - 2); }
  constexpr Z &operator*=(const Z &rhs) { return x = ll(x) * rhs.x % MOD, *this; }
  constexpr Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  constexpr Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  constexpr Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  constexpr Z &operator%=(const ll &rhs) { return x %= rhs, *this; }
  constexpr friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  constexpr friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  constexpr friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  constexpr friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  constexpr friend Z operator%(Z lhs, const ll &rhs) { return lhs %= rhs; }
  friend auto &operator>>(istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(ostream &o, const Z &z) { return o << z.x; }
};

constexpr int N = 402;

bitset<N> a[10][N][N];
int f[10][N][N];

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int n, q;
  cin >> n >> q;
  for (int i = 0, k; i < n; i++) {
    cin >> k;
    for (int j = 0, x, y, z; j < k; j++) {
      cin >> x >> y >> z;
      a[i][x][y][z] = 1;
    }
  }
  for (int ii = 0; ii < n; ii++) {
    for (int i = 1; i < N; i++)
      for (int j = 1; j < N; j++) a[ii][i][j] = a[ii][i][j] | a[ii][i - 1][j];
    for (int i = 1; i < N; i++)
      for (int j = 1; j < N; j++) a[ii][i][j] = a[ii][i][j] | a[ii][i][j - 1];
    for (int i = 1; i < N; i++)
      for (int j = 1; j < N; j++) f[ii][i][j] = a[ii][i][j]._Find_first();
  }

  auto solve = [&](int IQ, int EQ, int AQ) {
    int res = 0;
    for (int i = 0; i < n; i++) res += (AQ >= f[i][IQ][EQ]);
    return res;
  };

  ll seed;
  cin >> seed;
  std::mt19937 rng(seed);
  std::uniform_int_distribution<> u(1, 400);
  int lastans = 0;
  Z coef = power(seed, q), res = 0;
  Z inv = Z(1) / seed;
  for (int i = 1; i <= q; i++) {
    int IQ = (u(rng) ^ lastans) % 400 + 1;  // The IQ of the i-th friend
    int EQ = (u(rng) ^ lastans) % 400 + 1;  // The EQ of the i-th friend
    int AQ = (u(rng) ^ lastans) % 400 + 1;  // The AQ of the i-th friend
    lastans = solve(IQ, EQ, AQ);
    coef *= inv;
    res += lastans * coef;
  }
  cout << res << "\n";
}
