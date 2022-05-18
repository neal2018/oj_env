#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

namespace io {
constexpr int SIZE = 1 << 16;
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
  Read& operator>>(ll& x) { return x = read(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
} in;
}  // namespace io

constexpr ll inf = 1e9 + 10;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, k;
  io::in >> n >> m >> k;
  vector<ll> a(n);
  for (auto& x : a) io::in >> x;
  vector<pair<ll, ll>> e(m);
  for (auto& [u, v] : e) {
    io::in >> u >> v, u--, v--;
  }
  auto check = [&](ll mid) {
    vector<vector<ll>> g(n);
    vector<ll> deg(n);
    for (auto& [u, v] : e) {
      if (a[u] <= mid && a[v] <= mid) {
        g[v].push_back(u), deg[u]++;
      }
    }
    vector<ll> q, nq, dep(n);
    for (int i = 0; i < n; i++) {
      if (a[i] <= mid && deg[i] == 0) {
        q.push_back(i);
        dep[i] = 1;
      }
    }
    for (; q.size(); swap(q, nq), nq.clear()) {
      for (auto& node : q) {
        for (auto& ne : g[node]) {
          dep[ne] = max(dep[ne], dep[node] + 1);
          deg[ne]--;
          if (a[ne] <= mid && deg[ne] == 0) nq.push_back(ne);
        }
      }
    }
    if (*max_element(deg.begin(), deg.end()) > 0) return true;
    if (*max_element(dep.begin(), dep.end()) >= k) return true;
    return false;
  };
  ll l = 0, r = inf;
  while (l < r) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << (r == inf ? -1 : r) << "\n";
}
