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

struct Node {
  int a = 0, b = 0, c = 0;
};

Node pull(const Node& a, const Node& b) { return {a.a + b.a, a.b + b.b, a.c + b.c}; }

struct SegTree {
  int n;
  vector<Node> t;
  SegTree(int _n) : n(_n), t(2 * n){};
  void modify(int p, const Node& v) {
    t[p += n] = v;
    for (p /= 2; p; p /= 2) t[p] = pull(t[p * 2], t[p * 2 + 1]);
  }
  Node query(int l, int r) {
    Node left, right;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = pull(left, t[l++]);
      if (r & 1) right = pull(t[--r], right);
    }
    return pull(left, right);
  }
};

Node get_node(int c) {
  if (c == 1) return {1, 0, 0};
  if (c == 2) return {0, 1, 0};
  return {0, 0, 1};
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    ll res = 0;
    int n, m;
    cin >> n >> m;
    SegTree seg(n);
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      seg.t[i + n] = get_node(t);
    }
    for (int i = n - 1; i; i--) seg.t[i] = pull(seg.t[i * 2], seg.t[i * 2 + 1]);
    while (m--) {
      int x, y, z;
      cin >> x >> y >> z, x--;
      auto ans = [&] {
        seg.modify(x, get_node(y));
        auto all = seg.query(0, n);
        int all_sum = all.a + 2 * all.b + 3 * all.c;
        if (all_sum & 1) return -1;

        auto first = seg.query(0, z);
        int first_sum = first.a + 2 * first.b + 3 * first.c;
        if (first_sum * 2 > all_sum) {
          first = seg.query(z, n);
          first_sum = first.a + 2 * first.b + 3 * first.c;
        }
        int diff = all_sum / 2 - first_sum;
        int cur = 0;
        // a to c
        {
          int poss = min(first.a, all.c - first.c);
          int need = min(diff / 2, poss);
          cur += need, diff -= need * 2, first.c += need, first.a -= need;
        }
        // b to c;
        {
          int poss = min(first.b, all.c - first.c);
          int need = min(diff, poss);
          cur += need, diff -= need, first.c += need, first.b -= need;
        }
        // a to b;
        {
          int poss = min(first.a, all.b - first.b);
          int need = min(diff, poss);
          cur += need, diff -= need, first.b += need, first.a -= need;
        }
        if (diff == 0) {
          return cur;
        } else {
          return -1;
        }
      }();
      // cout << ans << "\n";
      res += ans;
    }
    cout << res << "\n";
    // cout << "\n";
  }
}
