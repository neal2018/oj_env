#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SIZE = 30;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<array<int, 2>> trie{{0, 0}}, dp{{0, 0}};
    int res = 0;
    // aj ^ i < ai ^ j
    // 0, 1
    // aj == i and ai != j
    // aj = i = 0, ai = 0, j = 1
    // aj = i = 0, ai = 1, j = 0
    // aj = i = 1, ai = 0, j = 1
    // aj = i = 1, ai = 1, j = 0
    //
    // i = 0, ai = 0, j = 1, aj = 0
    // i = 0, ai = 1, j = 0, aj = 0
    // i = 1, ai = 0, j = 1, aj = 1
    // i = 1, ai = 1, j = 0, aj = 1
    for (int i = 0; i < n; i++) {
      int x = a[i] ^ i, p = 0, cur = 1;
      for (int k = SIZE; k >= 0; k--) {
        int v = (x >> k) & 1;
        if (trie[p][!v] != 0) {
          cur = max(cur, dp[trie[p][!v]][(i >> k) & 1] + 1);
        }
        if (trie[p][v] == 0) break;
        p = trie[p][v];
      }
      p = 0;
      res = max(res, cur);
      for (int k = SIZE; k >= 0; k--) {
        int v = (x >> k) & 1;
        if (trie[p][v] == 0) {
          trie.push_back({0, 0}), dp.push_back({0, 0});
          trie[p][v] = int(trie.size()) - 1;
        }
        p = trie[p][v];
        int& temp = dp[p][(a[i] >> k) & 1];
        temp = max(temp, cur);
      }
    }
    cout << res << "\n";
  }
}
