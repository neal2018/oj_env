#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int inf = 1e9;

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
  Read &operator>>(int &x) { return x = read<int>(), *this; }
  Read &operator>>(ll &x) { return x = read<ll>(), *this; }
  Read &operator>>(long double &x) { return x = stold(read_s()), *this; }
  Read &operator>>(string &x) { return x = read_s(), *this; }
} in;
}  // namespace io

struct SAM {
  int last = 0, SZ = 26;
  vector<vector<int>> e = {vector<int>(SZ, -1)};
  vector<int> parent = {-1}, length = {0};
  SAM(int n) { e.reserve(2 * n), parent.reserve(2 * n), length.reserve(2 * n); }
  void extend(int c) {
    e.push_back(vector<int>(SZ, -1)), parent.push_back(0), length.push_back(length[last] + 1);
    int p = last, r = last = (int)e.size() - 1;
    for (; p != -1 && e[p][c] == -1; p = parent[p]) e[p][c] = r;
    if (p != -1) {
      int q = e[p][c];
      if (length[q] == length[p] + 1) {
        parent[r] = q;
      } else {
        e.push_back(e[q]), parent.push_back(parent[q]), length.push_back(length[p] + 1);
        int qq = parent[q] = parent[r] = (int)e.size() - 1;
        for (; p != -1 && e[p][c] == q; p = parent[p]) e[p][c] = qq;
      }
    }
  }
  vector<int> get_order() {
    ll sz = e.size();
    vector<int> order(sz), c(sz + 1);
    for (int i = 1; i < sz; i++) c[length[i]]++;
    for (int i = 1; i < sz; i++) c[i] += c[i - 1];
    for (int i = 1; i < sz; i++) order[c[length[i]]--] = i;
    reverse(order.begin(), order.end());
    return order;
  }
};

struct HeavyLight {
  int root = 0, n = 0;
  vector<int> parent, deep, hson, top, sz, dfn;
  HeavyLight(vector<vector<int>> &g, int _root)
      : root(_root), n(int(g.size())), parent(n), deep(n), hson(n, -1), top(n), sz(n), dfn(n, -1) {
    int cur = 0;
    function<int(int, int, int)> dfs = [&](int node, int fa, int dep) {
      deep[node] = dep, sz[node] = 1, parent[node] = fa;
      for (auto &ne : g[node]) {
        if (ne == fa) continue;
        sz[node] += dfs(ne, node, dep + 1);
        if (hson[node] == -1 || sz[ne] > sz[hson[node]]) hson[node] = ne;
      }
      return sz[node];
    };
    function<void(int, int)> dfs2 = [&](int node, int t) {
      top[node] = t, dfn[node] = cur++;
      if (hson[node] == -1) return;
      dfs2(hson[node], t);
      for (auto &ne : g[node]) {
        if (ne == parent[node] || ne == hson[node]) continue;
        dfs2(ne, ne);
      }
    };
    dfs(root, -1, 0), dfs2(root, root);
  }

  int lca(int x, int y) {
    while (top[x] != top[y]) {
      if (deep[top[x]] < deep[top[y]]) swap(x, y);
      x = parent[top[x]];
    }
    return deep[x] < deep[y] ? x : y;
  };
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = io::in;
  string s;
  cin >> s;
  SAM sam(int(s.size()));
  vector<int> last;
  last.reserve(s.size());
  for (auto &c : s) {
    sam.extend(c - 'a');
    last.push_back(sam.last);
  }
  ll sz = sam.e.size();
  auto &&order = sam.get_order();
  vector<vector<int>> g(sz);
  for (int i = 0; i < sz; i++) {
    if (sam.parent[i] != -1) g[sam.parent[i]].push_back(i);
  }
  // HeavyLight hld(g, 0);
  constexpr int LEVEL = 20;
  vector<vector<int>> parent(LEVEL, vector<int>(sz));
  function<void(int)> dfs = [&](int u) {
    for (int i = 1; i < LEVEL; ++i) {
      parent[i][u] = parent[i - 1][parent[i - 1][u]];
    }
    for (int v : g[u]) {
      parent[0][v] = u;
      dfs(v);
    }
  };
  dfs(0);
  vector<vector<int>> queries(sz);
  int q;
  cin >> q;
  vector<int> len(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r, l--, r--;
    len[i] = r - l + 1;
    auto node = last[r];
    // int p = hld.parent[hld.top[node]];
    // while (p != -1 && sam.length[p] >= r - l + 1) {
    //   node = p;
    //   p = hld.parent[hld.top[node]];
    // }
    // p = hld.parent[node];
    // while (p != -1 && sam.length[p] >= r - l + 1) {
    //   node = p;
    //   p = hld.parent[node];
    // }
    for (int j = LEVEL - 1; j >= 0; j--) {
      if (sam.length[parent[j][node]] >= r - l + 1) node = parent[j][node];
    }
    queries[node].push_back(i);
  }
  vector<int> res(q, -1);
  vector<set<int>> occ(sz);
  for (int i = 0; i < s.size(); i++) {
    occ[last[i]].insert(i);
  }
  vector<int> dist(sz, inf);
  for (auto &i : order) {
    if (i == 0) continue;
    for (auto &id : queries[i]) {
      res[id] = dist[i] == inf ? -1 : (dist[i] + len[id]);
    }
    if (sam.parent[i] > 0) {
      int p = sam.parent[i];
      dist[p] = min(dist[p], dist[i]);
      if (occ[i].size() > occ[p].size()) {
        swap(occ[i], occ[p]);
      }
      for (auto &x : occ[i]) {
        if (occ[p].count(x)) continue;
        auto it = occ[p].lower_bound(x);
        if (it != occ[p].end()) {
          dist[p] = min(dist[p], *it - x);
        }
        if (it != occ[p].begin()) {
          dist[p] = min(dist[p], x - *(--it));
        }
        occ[p].insert(x);
      }
    }
  }
  for (auto &x : res) cout << x << "\n";
}
