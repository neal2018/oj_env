// #pragma GCC optimize("Ofast")
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
}  // namespace io

constexpr int inf = 1e8;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  // auto cin = io::in;
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    vector<int> mouse(10);
    for (auto& c : a) mouse[c]++;
    vector<int> hole(10, m);
    auto greedy = [&] {
      ll res = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q0, q1;
      q1.emplace(inf, inf);
      for (int i = 0; i < 10; i++) {
        int count = mouse[i], pos = i;
        while (count) {
          auto [val, d] = q1.top();
          q1.pop();
          int add = min(count, d);
          res += ll(val + pos) * add;
          if (d > add) q1.emplace(val, d - add);
          q0.emplace(-pos * 2 - val, add);
          count -= add;
        }
        count = hole[i];
        int f = 0;
        for (; f < count && q0.size() && q0.top().first + pos < 0;) {
          auto [val, d] = q0.top();
          q0.pop();
          int add = min(d, count - f);
          res += ll(val + pos) * add;
          f += add;
          if (d > add) q0.emplace(val, d - add);
          q1.emplace(-pos * 2 - val, add);
        }
        if (f < count) q1.emplace(-pos, count - f);
        if (f) q0.emplace(-pos, f);
      }
      return res;
    };
    auto cost = greedy();
    cout << cost << "\n";
    for (const auto x : a) {
      mouse[x]--;
      for (int j = 0; j < 10; j++) {
        if (hole[j] == 0) continue;
        hole[j]--;
        auto flow = greedy();
        if (flow + abs(x - j) == cost) {
          cout << j;
          cost -= abs(x - j);
          break;
        }
        hole[j]++;
      }
    }
    cout << "\n";
  }
}
