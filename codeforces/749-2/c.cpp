#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094 1:53
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, m, q, a, b;
  cin >> n >> m;
  vector<string> s(n);
  for (auto& x : s) cin >> x;
  cin >> q;
  vector<int> check(m + 1), pre(m + 2);  // if select i and i-1, NO
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') check[j] = 1;
  for (int i = 0; i < m; i++) pre[i + 1] = pre[i] + check[i];
  // ranges::adjacent_find()
  while (q--) {
    cin >> a >> b;
    a--, b--;
    cout << (pre[b + 1] - pre[a + 1] ? "NO\n" : "YES\n");
  }
}