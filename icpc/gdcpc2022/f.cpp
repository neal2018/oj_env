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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int n;
  cin >> n;
  vector<array<int, 4>> event(2 * n);  // number, is_leave, kind, id
  for (int i = 0, x, s, e, type; i < n; i++) {
    cin >> x >> s >> e >> type, s--, e--;
    event[s] = {x, 0, type, i};
    event[e] = {x, 1, type, i};
  }
  array<set<int>, 5> seat;
  vector<int> seat_occ;
  vector<int> id2seat(n);
  for (auto& [x, is_leave, kind, id] : event) {
    if (is_leave == 0) {
      int seat_id = -1;
      if (kind == 0) {
        if (seat[0].size()) {
          seat_id = *seat[0].begin();
          seat[0].erase(seat[0].begin());
        }
      } else {
        vector<pair<int, int>> candidate;
        for (int i = 0; i <= 4 - x; i++) {
          if (seat[i].size()) candidate.push_back({*seat[i].begin(), i});
        }
        if (candidate.size()) {
          sort(candidate.begin(), candidate.end());
          seat_id = candidate[0].first;
          int i = candidate[0].second;
          seat[i].erase(seat[i].begin());
        }
      }
      if (seat_id == -1) {
        seat_id = int(seat_occ.size());
        seat_occ.push_back(0);
      }
      seat_occ[seat_id] += x;
      seat[seat_occ[seat_id]].insert(seat_id);
      id2seat[id] = seat_id;
    } else {
      int occ = seat_occ[id2seat[id]];
      seat[occ].erase(id2seat[id]);
      seat[occ - x].insert(id2seat[id]);
      seat_occ[id2seat[id]] -= x;
    }
  }
  cout << seat_occ.size() << '\n';
}
