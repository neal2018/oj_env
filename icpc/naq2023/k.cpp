#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
// #define int long long
const int M = 1000005;
const int N = 100005;
struct node {
  int a, b, c, id;
} E[M * 4];
struct P {
  int t, c, id;
};
bool cmp(node x, node y) { return x.c < y.c; }
vector<P> G[N];
int par[N], f[N];
int n, m;
long long sum, d[N];
long long td[N], tc[N], cost, ans[4 * M];
bool mark[4 * M], use[4 * M];
int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}
void dfs(int x) {
  int to, c, id;
  for (int i = 0; i < G[x].size(); i++) {
    to = G[x][i].t;
    c = G[x][i].c;
    id = G[x][i].id;
    if (!d[to]) {
      d[to] = d[x] + 1;
      td[to] = id;
      tc[to] = c;
      f[to] = x;
      dfs(to);
    }
  }
}
void update(int a, int b) {
  long long id, c;
  if (d[a] > d[b]) swap(a, b);
  while (d[a] < d[b]) {
    id = td[b];
    c = tc[b];
    if (!use[id]) ans[id] = sum - c + cost, use[id] = 1;
    b = f[b];
  }
  while (a != b) {
    id = td[b];
    c = tc[b];
    if (!use[id]) ans[id] = sum - c + cost, use[id] = 1;
    b = f[b];
    id = td[a];
    c = tc[a];
    if (!use[id]) ans[id] = sum - c + cost, use[id] = 1;
    a = f[a];
  }
}
void made() {
  sort(E + 1, E + 1 + m, cmp);
  int res = n, a, b, c, id, fa, fb;
  for (int i = 1; i <= m && res != 1; i++) {
    a = E[i].a;
    b = E[i].b;
    c = E[i].c;
    id = E[i].id;
    fa = find(a);
    fb = find(b);
    if (fa == fb) continue;
    G[a].push_back((P){b, c, id});
    G[b].push_back((P){a, c, id});
    sum += c;
    res--;
    par[fa] = fb;
    mark[id] = 1;
  }
  d[1] = 1;
  dfs(1);
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int a, b, c;
  memset(ans, -1, sizeof(ans));
  auto cin = Read{};
  cin >> n >> m;
  // scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    // scanf("%d%d%d", &a, &b, &c);
    E[i] = (node){a, b, c, i};
  }
  for (int i = 1; i <= n; i++) par[i] = i;
  made();
  for (int i = 1; i <= m; i++)
    if (!mark[E[i].id]) {
      a = E[i].a;
      b = E[i].b;
      c = E[i].c;
      cost = c;
      update(a, b);
    }
  long long res = 0;
  for (int i = 1; i <= m; i++) {
    // if (!mark[i])
    //   printf("%d\n", sum);
    // else
    //   printf("%d\n", ans[i]);
    if (!mark[i])
      res = max(res, sum);
    else
      res = max(res, ans[i]);
  }
  cout << res << "\n";
  return 0;
}
