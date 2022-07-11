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
  vector<vector<int>> g(n);
  for (int i = 1, f; i < n; i++) {
    cin >> f, f--;
    g[f].push_back(i), g[i].push_back(f);
  }
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<int> maxi(n, -1), submaxi(n, -1);
  for (int i = 0; i < n; i++) {
    int first = -1, second = -1;
    for (auto& ne : g[i]) {
      if (first == -1 || a[ne] > a[first]) {
        second = first, first = ne;
      } else if (second == -1 || a[ne] > a[second]) {
        second = ne;
      }
    }
    maxi[i] = first, submaxi[i] = second;
  }
  vector<array<ll, 2>> memo(n, {-1, -1});
  function<ll(int, int)> dfs = [&](int node, int fa) {
    int f = fa == maxi[node];
    if (memo[node][f] != -1) return memo[node][f];
    if (f) {
      if (submaxi[node] == -1) return a[node];
      return memo[node][f] = a[node] + dfs(submaxi[node], node);
    } else {
      if (maxi[node] == -1) return a[node];
      return memo[node][f] = a[node] + dfs(maxi[node], node);
    }
  };
  ll start = -1, res = -1;
  for (int i = 0; i < n; i++) {
    auto cur = dfs(i, -2);
    if (cur > res) {
      res = cur, start = i;
    }
  }
  cout << start + 1 << "\n";
  cout << res << "\n";
}
