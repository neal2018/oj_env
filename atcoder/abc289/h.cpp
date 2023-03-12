#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Read {
  static constexpr int SIZE = 1 << 16;
  static inline char buf[SIZE], *head, *tail;
  static char get_char() {
    if (head == tail) tail = (head = buf) + fread(buf, 1, SIZE, stdin);
    return *head++;
  }
  static string read_s() {
    string str;
    char c = get_char();
    while (c == ' ' || c == '\n' || c == '\r') c = get_char();
    while (c != ' ' && c != '\n' && c != '\r') str += c, c = get_char();
    return str;
  }
  template <typename T>
  Read& operator>>(T& x) {
    int f = 1;
    char c = get_char();
    for (x = 0; !isdigit(c); c = get_char()) (c == '-') && (f = -1);
    for (; isdigit(c); c = get_char()) x = x * 10 + c - '0';
    return x *= f, *this;
  }
  Read& operator>>(string& x) { return x = read_s(), *this; }
  Read& operator>>(long double& x) { return x = stold(read_s()), *this; }
};


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = Read{};
  constexpr int MAX_N = 2000;
  int n, m;
  cin >> n >> m;
  vector<bitset<MAX_N>> g(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v, u--, v--;
    g[u][v] = 1;
  }
  int q;
  cin >> q;
  vector<array<int, 2>> queries(q);
  vector<int> res(q, -1);
  for (auto& [s, t] : queries) cin >> s >> t, s--, t--;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (g[i][k]) g[i] |= g[k];
    }
    for (int i = 0; i < q; i++) {
      auto& [s, t] = queries[i];
      if (g[s][t] && res[i] == -1) {
        res[i] = max({s, t, k}) + 1;
      }
    }
  }
  for (auto& x : res) cout << x << "\n";
}