#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
  Read& operator>>(auto& x) { return x = read(), *this; }
  Read& operator>>(ld& x) { return x = stold(read_s()), *this; }
} in;
}  // namespace io

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, m, k;
  io::in >> m >> n >> k;
  vector<map<ll, ll>> points(n);
  points[0][0] = 0;
  points[1][k + 1] = 1;
  ll cnt = 2;
  vector<pair<array<ll, 4>, ld>> edges(m);
  for (auto& [v, p] : edges) {
    auto& [a, b, s, t] = v;
    io::in >> a >> b >> s >> t >> p, t++;
    if (points[a].count(s) == 0) points[a][s] = cnt++;
    if (points[b].count(t) == 0) points[b][t] = cnt++;
  }
  vector<vector<pair<ll, ld>>> g(cnt);
  for (auto& [v, p] : edges) {
    auto& [a, b, s, t] = v;
    g[points[a][s]].push_back({points[b][t], p});
  }
  vector<ll> nex(cnt, -1);
  for (auto& mp : points) {
    if (mp.size() == 0) continue;
    for (auto it = mp.begin(), it2 = ++mp.begin(); it2 != mp.end(); it++, it2++) {
      nex[it->second] = it2->second;
    }
  }

  vector<ld> dp(cnt, -1);
  dp[1] = 1;
  function<void(ll)> dfs = [&](ll node) {
    if (dp[node] != -1) return;
    ld addon = 0;
    if (nex[node] != -1) {
      dfs(nex[node]);
      addon = dp[nex[node]];
    }
    dp[node] = addon;
    for (auto& [ne, p] : g[node]) {
      dfs(ne);
      dp[node] = max(dp[node], p * dp[ne] + (1 - p) * addon);
    }
  };
  dfs(0);
  cout << dp[0] << "\n";
}
