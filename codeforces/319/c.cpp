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

constexpr int BLOCK = 1024;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int n;
  cin >> n;
  vector<array<int, 2>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;
  vector<vector<int>> blocks(BLOCK);
  for (int i = 0; i < n; i++) blocks[a[i][0] / BLOCK].push_back(i);
  for (int i = 0; auto& bin : blocks) {
    if (i & 1) {
      sort(bin.begin(), bin.end(), [&](int x, int y) { return a[x][1] < a[y][1]; });
    } else {
      sort(bin.begin(), bin.end(), [&](int x, int y) { return a[x][1] > a[y][1]; });
    }
    for (auto& x : bin) cout << x + 1 << " ";
    i++;
  }
}
