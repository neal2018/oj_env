#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto get_next(string& pat) {
  int m = (int)pat.length();
  vector<int> nex(m);
  for (int i = 1, j = 0; i < m; i++) {
    while (j && pat[j] != pat[i]) j = nex[j - 1];
    if (pat[j] == pat[i]) j++;
    nex[i] = j;
  }
  return nex;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  int q;
  cin >> s >> q;
  int n = int(s.size());
  auto&& nex = get_next(s);
  nex.reserve(2e6);
  vector<vector<int>> trie = {vector<int>(26)};
  vector<int> nums = {0};
  while (q--) {
    string t;
    cin >> t;
    int m = int(t.size());
    for (int i = 0, p = 0; i < m; i++) {
      int c = t[i] - 'a';
      if (trie[p][c] == 0) break;
      p = trie[p][c], nex.push_back(nums[p]);
    }
    int added = int(nex.size()) - n;
    while (nex.size() < n + m) nex.push_back(0);
    s += t;
    for (int i = n + added, j = nex[n + added - 1]; i < n + m; i++) {
      while (j && s[j] != s[i]) {
        j = nex[j - 1];
      }
      if (s[j] == s[i]) j++;
      nex[i] = j;
    }
    for (int i = n; i < n + m; i++) {
      cout << nex[i] << " ";
    }
    cout << "\n";
    for (int i = 0, p = 0; i < m; i++) {
      int c = t[i] - 'a';
      if (trie[p][c] == 0) {
        trie.push_back(vector<int>(26));
        nums.push_back(0);
        trie[p][c] = int(trie.size()) - 1;
      }
      p = trie[p][c], nums[p] = nex[n + i];
    }
    while (m--) {
      s.pop_back();
      nex.pop_back();
    }
  }
}
