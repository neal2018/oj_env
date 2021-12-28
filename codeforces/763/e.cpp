#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<int> l(n), r(n), dup(n), in(n), need(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> r[i], l[i]--, r[i]--;
  string res(n, '?');
  int cnt = 0;
  function<void(int)> dfs = [&](int node) {
    if (~l[node]) dfs(l[node]);
    res[cnt] = s[node];
    in[node] = cnt++;
    if (~r[node]) dfs(r[node]);
  };
  dfs(0);
  for (int i = n - 2; i >= 0; i--) {
    if (res[i] == res[i + 1]) {
      need[i] = need[i + 1];
    } else {
      need[i] = (res[i] < res[i + 1]);
    }
  }
  function<int(int, int)> dfs1 = [&](int node, int dep) {
    int f = 0;
    if (~l[node] && dfs1(l[node], dep + 1)) f = 1;
    if (f) {
      dup[in[node]] = 1;
    } else if (k >= dep && need[in[node]]) {
      k -= dep, f = 1, dup[in[node]] = 1;
    }
    if (~r[node] && f) dfs1(r[node], 1);
    return f;
  };
  dfs1(0, 1);
  for (int i = 0; i < n; i++) {
    cout << res[i];
    if (dup[i]) cout << res[i];
  }
  cout << "\n";
}
