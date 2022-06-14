#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

namespace io {
constexpr int SIZE = 1 << 16;
char buf[SIZE], *head, *tail;
char get_char() {
  if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
  return *head++;
}
int read() {
  int x = 0, f = 1;
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
  Read& operator>>(int& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
  Read& operator>>(string& x) { return x = read_s(), *this; }
} in;
}  // namespace io

struct TwoSat {
  int n;
  vector<vector<int>> g;
  vector<bool> res;
  TwoSat(int _n) : n(_n), g(2 * n), res(n) {}
  void add_clause(int u, bool is_u, int v, bool is_v) {
    g[2 * u + !is_u].push_back(2 * v + is_v);
    g[2 * v + !is_v].push_back(2 * u + is_u);
  }
  bool solve() {
    int cnt = 0, now = 0;
    vector<int> dfn(2 * n, -1), low(2 * n), id(2 * n, -1), stk;
    function<void(int)> tarjan = [&](int node) {
      dfn[node] = low[node] = now++, stk.push_back(node);
      for (auto& ne : g[node]) {
        if (dfn[ne] == -1) {
          tarjan(ne);
          low[node] = min(low[node], low[ne]);
        } else if (id[ne] == -1) {
          low[node] = min(low[node], dfn[ne]);
        }
      }
      if (dfn[node] == low[node]) {
        while (true) {
          auto v = stk.back();
          id[v] = cnt;
          stk.pop_back();
          if (v == node) break;
        }
        ++cnt;
      }
    };
    for (int i = 0; i < 2 * n; ++i) {
      if (dfn[i] == -1) tarjan(i);
    }
    for (int i = 0; i < n; ++i) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      res[i] = id[2 * i] > id[2 * i + 1];
    }
    return true;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  io::in >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0, u, v; i < n - 1; i++) {
    io::in >> u >> v, u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> depth(n), parent(n, -1);
  function<void(int, int)> get_dep = [&](int node, int fa) {
    if (fa != -1) depth[node] = depth[fa] + 1, parent[node] = fa;
    for (auto& ne : g[node]) {
      if (ne != fa) get_dep(ne, node);
    }
  };
  get_dep(0, -1);
  auto get_path = [&](int x, int y) {
    vector<int> left, right;
    while (x != y) {
      if (depth[x] > depth[y]) {
        left.push_back(x);
        x = parent[x];
      } else {
        right.push_back(y);
        y = parent[y];
      }
    }
    left.push_back(x);
    left.insert(left.end(), right.rbegin(), right.rend());
    return left;
  };
  TwoSat ts(n + q);
  string positive(n, 'a'), negative(n, 'b');
  vector<tuple<int, int, string>> queries(q);
  for (auto& [x, y, s] : queries) {
    io::in >> x >> y >> s, x--, y--;
    int sz = int(s.size());
    auto path = get_path(x, y);
    for (int i = 0; i < sz; i++) {
      positive[path[i]] = s[i];
      negative[path[i]] = s[sz - 1 - i];
    }
  }
  for (auto id : views::iota(0, q)) {
    auto& [x, y, s] = queries[id];
    int sz = int(s.size());
    auto path = get_path(x, y);
    for (int i = 0; i < sz; i++) {
      if (positive[path[i]] != s[i]) ts.add_clause(path[i], 0, n + id, 1);
      if (negative[path[i]] != s[i]) ts.add_clause(path[i], 1, n + id, 1);
      if (positive[path[i]] != s[sz - 1 - i]) ts.add_clause(path[i], 0, n + id, 0);
      if (negative[path[i]] != s[sz - 1 - i]) ts.add_clause(path[i], 1, n + id, 0);
    }
  }
  auto&& nice = ts.solve();
  if (!nice) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      cout << (ts.res[i] ? positive[i] : negative[i]);
    }
    cout << "\n";
  }
}
