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
} in;
}  // namespace io

struct SegTree {
  int n;
  vector<vector<pair<int, ll>>> g;
  SegTree(int _n) : n(_n), g(4 * n) {}
  void add_edge(int u, int v, ll w) { g[u].push_back({v, w}); }
  void add_edge_wrap(int u, int v, ll w, ll d = 1) {
    if (d == 1) {
      add_edge(u, 2 * n + v, w);
    } else {
      add_edge(v, u, w);
    }
  }
  void query(int l, int r, int from, ll w, int d = 1) {
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) add_edge_wrap(3 * n + from, l++, w, d);
      if (r & 1) add_edge_wrap(3 * n + from, --r, w, d);
    }
  }
};

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  int n, q, s;
  cin >> n >> q >> s, s--;
  SegTree seg(n);
  for (auto i : views::iota(0, n)) {
    seg.add_edge(3 * n + i, n + i, 0);
  }
  for (auto i : views::iota(1, n)) {
    seg.add_edge(2 * i, i, 0);
    seg.add_edge(2 * i + 1, i, 0);
    seg.add_edge(2 * n + i, 2 * n + 2 * i, 0);
    seg.add_edge(2 * n + i, 2 * n + 2 * i + 1, 0);
  }
  while (q--) {
    int t;
    ll w;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v >> w, u--, v--;
      seg.add_edge(3 * n + u, 3 * n + v, w);
    } else {
      int u, l, r;
      cin >> u >> l >> r >> w, u--, l--;
      seg.query(l, r, u, w, t == 2 ? 1 : -1);
    }
  }
  int root = 3 * n + s;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.emplace(0, root);
  vector<ll> dist(4 * n, inf);
  dist[root] = 0;
  while (pq.size()) {
    auto [cost, node] = pq.top();
    pq.pop();
    if (cost > dist[node]) continue;
    for (auto& [ne, w] : seg.g[node]) {
      if (cost + w < dist[ne]) {
        dist[ne] = cost + w, pq.emplace(dist[ne], ne);
      }
    }
  }
  for (int i = 3 * n; i < 4 * n; i++) {
    cout << (dist[i] == inf ? -1 : dist[i]) << " ";
  }
}
