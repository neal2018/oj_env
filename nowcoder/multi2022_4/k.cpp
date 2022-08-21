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
  Read& operator>>(int& x) { return x = read<int>(), *this; }
  Read& operator>>(ll& x) { return x = read<ll>(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
  Read& operator>>(string& x) { return x = read_s(), *this; }
} in;
}  // namespace io;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n;
  cin >> n;
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    res += [&] {
      for (ll cur = 1, t = i, len = 1;; cur++) {
        t = (10 * t) % n, len *= 10;
        if (len >= n) return cur;
        ll left = t, right = (t + len - 1) % n + 1;
        if (left < right) {
          if (left <= i + 1 && i + 1 < right) return cur;
        } else {
          if (left <= i + 1 || i + 1 < right) return cur;
        }
      }
    }();
  }
  if (n == 1) res = 0;
  cout << res << "\n";
}
