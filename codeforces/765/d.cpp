#include <bits/stdc++.h>
using namespace std;
constexpr int SIZE = 2;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
  if (k == 0) {
    cout << n << "\n";
    for (int i = 0; i < n; i++) cout << i + 1 << " \n"[i == n - 1];
    return 0;
  }
  sort(a.begin(), a.end());
  int bits = 0;
  while ((1 << bits) <= k) bits++;
  vector<int> res;
  for (int i = 0, j; i < n; i = j) {
    j = i;
    while (j < n && (a[j].first >> bits) == (a[i].first >> bits)) j++;
    vector trie(1, vector(SIZE, 0));
    map<int, pair<int, int>> mp;
    for (int t = i; t < j; t++) {
      int x = a[t].first, node = 0, found = 1;
      for (int jj = bits - 1; jj >= 0; jj--) {
        int p = (x >> jj) & 1;
        if (trie[node][!p]) {
          node = trie[node][!p];
        } else if (trie[node][p]) {
          node = trie[node][p];
        } else {
          found = 0;
          break;
        }
      }
      if (found && (mp[node].first ^ x) >= k) {
        res.push_back(a[t].second);
        res.push_back(mp[node].second);
        break;
      }
      node = 0;
      for (int jj = bits - 1; jj >= 0; jj--) {
        int p = (x >> jj) & 1;
        if (!trie[node][p]) {
          trie.push_back(vector(SIZE, 0));
          trie[node][p] = (int)trie.size() - 1;
        }
        node = trie[node][p];
      }
      mp[node] = a[t];
      if (t == j - 1) res.push_back(a[t].second);
    }
  }
  if (res.size() <= 1) {
    cout << "-1\n";
  } else {
    cout << res.size() << "\n";
    for (auto& x : res) cout << x + 1 << " ";
    cout << "\n";
  }
}