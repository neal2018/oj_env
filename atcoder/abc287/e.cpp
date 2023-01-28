#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<int>> trie{vector<int>(26)};
  vector<set<int>> id{set<int>{}};

  for (int _ = 0; _ < n; _++) {
    auto s = a[_];
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (trie[p][c] == 0) {
        trie[p][c] = int(trie.size());
        trie.push_back(vector<int>(26));
        id.push_back(set<int>{});
      }
      p = trie[p][c];
      id[p].insert(_);
    }
  }
  for (int _ = 0; _ < n; _++) {
    auto s = a[_];
    int p = 0, res = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      p = trie[p][c];
      if (id[p].size() > id[p].count(_)) res = i + 1;
    }
    cout << res << "\n";
  }
}