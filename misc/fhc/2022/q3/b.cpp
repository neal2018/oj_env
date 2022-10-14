#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print(__int128 x) {
  constexpr ll P = 1e18;
  if (x < P) {
    cout << ll(x) << "\n";
  } else {
    cout << ll(x / P) << setw(18) << setfill('0') << ll(x % P) << endl;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    vector<vector<int>> trie{vector<int>(26)};
    vector<int> end{0};
    for (int _ = 0; _ < n; _++) {
      int m;
      cin >> m;
      vector<vector<pair<int, int>>> g(m);
      for (int i = 1; i < m; i++) {
        int p;
        char c;
        cin >> p >> c, p--;
        g[p].push_back({i, c - 'a'});
      }
      vector<pair<int, int>> q{{0, 0}}, nq;
      for (; q.size(); swap(q, nq), nq.clear()) {
        for (auto [node, p] : q) {
          end[p]++;
          for (auto& [ne, c] : g[node]) {
            if (trie[p][c] == 0) {
              trie[p][c] = int(trie.size());
              trie.push_back(vector<int>(26));
              end.push_back(0);
            }
            nq.push_back({ne, trie[p][c]});
          }
        }
      }
    }
    __int128 res = 0;
    for (auto& x : end) {
      auto k = __int128(x);
      res += k * (n - k) * (n - k - 1) / 2 + k * (k - 1) / 2 * (n - k) + k * (k - 1) * (k - 2) / 6;
    }
    print(res);
  }
}
