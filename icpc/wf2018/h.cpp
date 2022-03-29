#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

namespace io {
constexpr int SIZE = 4e6 + 10;
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
  Read& operator>>(auto& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
} in;
}  // namespace io

constexpr ld offset = 0.1;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, w, h;
  io::in >> n >> w >> h;
  auto to_num = [&](const pair<ll, ll>& p) {
    if (p.second == 0) return p.first;
    if (p.first == w) return w + p.second;
    if (p.second == h) return 2 * w + h - p.first;
    return 2 * w + 2 * h - p.second;
  };
  auto to_point = [&](ld x) -> pair<ld, ld> {
    if (x <= w) return {x, 0};
    if (x <= w + h) return {w, x - w};
    if (x <= 2 * w + h) return {2 * w + h - x, h};
    return {0, 2 * w + 2 * h - x};
  };
  auto is_same_edge = [&](const pair<ld, ld>& p1, const pair<ld, ld>& p2) {
    if (p1.first == 0 && p2.first == 0) return true;
    if (p1.first == w && p2.first == w) return true;
    if (p1.second == 0 && p2.second == 0) return true;
    if (p1.second == h && p2.second == h) return true;
    return false;
  };
  multiset<ll> start, ending;
  vector<pair<ll, ll>> cand;
  cand.reserve(2 * n);
  for (ll i = 0, x1, y1, x2, y2; i < n; i++) {
    io::in >> x1 >> y1 >> x2 >> y2;
    ll num1 = to_num({x1, y1}), num2 = to_num({x2, y2});
    if (num1 > num2) swap(num1, num2);
    start.insert(num1), ending.insert(num2);
    cand.push_back({num1, num2});
    cand.push_back({num2, num1 + 2 * w + 2 * h});
  }
  sort(cand.begin(), cand.end());

  for (int i = 0; i < n; i++) {
    auto& [num1, num2] = cand[i];
    if (*ending.begin() > *start.rbegin()) {
      cout << 1 << '\n';
      auto p1 = to_point(num1 - offset), p2 = to_point(*start.rbegin() + offset);
      if (is_same_edge(p1, p2)) {
        p2 = to_point(*ending.begin() - offset);
      }
      cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second << '\n';
      return 0;
    }
    start.erase(start.find(num1)), ending.erase(ending.find(num2));
    start.insert(num2), ending.insert(num1 + 2 * w + 2 * h);
  }
  cout << 2 << "\n";
  cout << 0 << " " << offset << " " << w - offset << " " << h << "\n";
  cout << w << " " << offset << " " << offset << " " << h << "\n";
}
