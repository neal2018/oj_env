// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <cmath>
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
  putchar(x % 10 + '0');
}
void println(int x) { print(x), putchar('\n'); }
struct Read {
  Read& operator>>(int& x) { return x = read<int>(), *this; }
  Read& operator>>(ll& x) { return x = read<ll>(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
  Read& operator>>(string& x) { return x = read_s(), *this; }
} in;
}  // namespace io

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int n, m, maxi = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x, maxi = max(maxi, x);
  vector<array<int, 3>> qs(m);
  for (int i = 0; i < m; i++) {
    auto& [x, y, z] = qs[i];
    cin >> x >> y, x--, z = i;
  }
  int SIZE = max(1, (int)(n / sqrt(m)));
  sort(qs.begin(), qs.end(), [&](auto& x, auto& y) {
    return pair{x[0] / SIZE, x[1]} < pair{y[0] / SIZE, y[1]};
  });
  vector<ll> seen(maxi + 1);
  vector<ll> res(m);
  ll cur = 0;
  auto add = [&](int x) {
    cur -= seen[x] * seen[x] * x;
    seen[x]++;
    cur += seen[x] * seen[x] * x;
  };
  auto del = [&](int x) {
    cur -= seen[x] * seen[x] * x;
    seen[x]--;
    cur += seen[x] * seen[x] * x;
  };
  int L = 0, R = 0;  //  store [L, R)
  for (auto& [l, r, id] : qs) {
    while (L > l) add(a[--L]);
    while (R < r) add(a[R++]);
    while (L < l) del(a[L++]);
    while (R > r) del(a[--R]);
    res[id] = cur;
  }
  for (auto& x : res) cout << x << "\n";
}
