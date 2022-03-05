#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

namespace io {
constexpr int BUFFER_SIZE = 1 << 16;
char buffer[BUFFER_SIZE], *head, *tail;
char get_char() {
  if (head == tail) {
    int l = (int)fread(buffer, 1, BUFFER_SIZE, stdin);
    tail = (head = buffer) + l;
  }
  return *head++;
}
int read() {
  int x = 0, f = 1;
  char c = get_char();
  for (; !isdigit(c); c = get_char())
    if (c == '-') f = -1;
  for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
  return x * f;
}
void print(int x) {
  if (x > 9) print(x / 10);
  putchar(x % 10 | '0');
}
void println(int x) { print(x), putchar('\n'); }
}  // namespace io

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = io::read();
  while (T--) {
    int n = io::read(), q = io::read();
    vector<ll> a(n);
    for (auto& x : a) x = io::read();
    while (q--) {
      int x = io::read(), y = io::read();
      x--;
    }
  }
}
