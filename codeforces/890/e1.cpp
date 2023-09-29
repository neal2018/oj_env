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

constexpr size_t MAX = 2'000'000;

template <size_t len = 1>
int solve_knapsack(const vector<int>& inputs, const int n) {
  if (n >= len) {
    return solve_knapsack<min(len * 2, MAX)>(inputs, n);
  }
  bitset<len> dp;
  dp[0] = 1;
  for (const auto x : inputs) {
    dp |= (dp << x);
  }
  int res = 0;
  auto get_dist = [&](auto i) { return abs(i - (n - i)); };
  for (int i = 0; i <= n; i++) {
    if (dp[i] && get_dist(res) > get_dist(i)) {
      res = i;
    }
  }
  return res;
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto cin = Read{};
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p, p--;
    g[p].push_back(i);
  }
  vector<int> sz(n);
  ll res = 0;
  function<void(int)> dfs = [&](int node) {
    vector<int> son;
    for (auto& ne : g[node]) {
      dfs(ne);
      sz[node] += sz[ne];
      son.push_back(sz[ne]);
    }
    sort(son.rbegin(), son.rend());
    auto get_closest = [&]() -> ll {
      if (son.size() == 0) return 0;
      const auto total = sz[node];
      if (son[0] * 2 >= total) return son[0];
      vector<int> inputs;
      for (int i = 0, j = 0; i < son.size(); i = j) {
        for (j = i; j < son.size() && son[i] == son[j];) j++;
        int cnt = j - i;
        for (int base = 1; cnt; base *= 2) {
          int minus = min(cnt, base);
          cnt -= minus;
          inputs.push_back(son[i] * minus);
        }
      }
      return solve_knapsack(inputs, total);
    };
    const auto closest = get_closest();
    res += (sz[node] - closest) * closest;
    sz[node]++;
  };
  dfs(0);
  cout << res << "\n";
}
