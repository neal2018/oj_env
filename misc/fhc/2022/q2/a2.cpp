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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n, m, maxi = 0, change_cnt = 0, ask_cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, maxi = max(maxi, x);
    cin >> m;
    vector<array<int, 3>> qs;
    qs.reserve(m);
    vector<pair<int, int>> change;
    change.reserve(m);
    for (int i = 0, x, y; i < m; i++) {
      int op;
      cin >> op >> x >> y, x--;
      if (op == 1) {
        change.emplace_back(x, y), change_cnt++;
        maxi = max(maxi, y);
      } else {
        if ((y - x) % 2 == 1) qs.push_back({x, y, change_cnt}), ask_cnt++;
      }
    }
    int SIZE = (int)cbrt(1ll * n * change_cnt) + 1;
    sort(qs.begin(), qs.end(), [&](auto& x, auto& y) {
      return array{x[0] / SIZE, x[1] / SIZE, x[2]} < array{y[0] / SIZE, y[1] / SIZE, y[2]};
    });
    vector<int> seen(maxi + 1);
    int res = 0;
    int cur = 0;
    int two = 0, neg_one = 0;
    auto flip = [&](int i, int d) {
      cur -= abs(seen[i]);
      if (seen[i] == 2) two--;
      if (seen[i] == -1) neg_one--;
      seen[i] += d;
      cur += abs(seen[i]);
      if (seen[i] == 2) two++;
      if (seen[i] == -1) neg_one++;
    };
    auto add_left = [&](int l, int r) {
      flip(a[l - 1], 1);
      if ((r - l) % 2 == 1) {
        int mid = (l + r) / 2;
        flip(a[mid], -2);
      }
    };
    auto add_right = [&](int l, int r) {
      flip(a[r], -1);
      if ((r - l) % 2 == 0) {
        int mid = (l + r) / 2;
        flip(a[mid], 2);
      }
    };
    auto del_left = [&](int l, int r) {
      flip(a[l], -1);
      if ((r - l) % 2 == 0) {
        int mid = (l + r) / 2;
        flip(a[mid], 2);
      }
    };
    auto del_right = [&](int l, int r) {
      flip(a[r - 1], 1);
      if ((r - l) % 2 == 1) {
        int mid = (l + r) / 2;
        flip(a[mid], -2);
      }
    };
    int L = 0, R = 0, now = 0;  //  store [L, R)
    auto update = [&](int time) {
      auto [p, v] = change[time];
      if (L <= p && p < R) {
        if (p <= (L + R) / 2) {
          flip(a[p], -1);
          flip(v, 1);
        } else {
          flip(a[p], 1);
          flip(v, -1);
        }
      }
      change[time].second = a[p], a[p] = v;
    };
    for (auto& [l, r, tt] : qs) {
      while (L > l) add_left(L, R), L--;
      while (R < r) add_right(L, R), R++;
      while (L < l) del_left(L, R), L++;
      while (R > r) del_right(L, R), R--;
      while (now < tt) update(now++);
      while (now > tt) update(--now);
      // cout << l << " " << r << " " << s.substr(l, r - l) << " " << cur << "\n";
      if (cur == 1 || (two == 1 && neg_one == 1 && cur == 3 && seen[a[(l + r) / 2]] == 2)) res++;
    }
    cout << res << "\n";
  }
}
