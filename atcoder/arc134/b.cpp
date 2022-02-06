#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, vector<int>> mp;
  for (int i = 0; i < n; i++) mp[s[i]].push_back(i);
  function<void(int, int)> solve = [&](int left, int right) {
    for (int pos = left; pos < right; pos++) {
      int maxi = s[pos] - 'a';
      for (int i = 0; i < maxi; i++) {
        char c = char(i + 'a');
        while (mp[c].size() && !(pos <= mp[c].back() && mp[c].back() < right)) {
          mp[c].pop_back();
        }
        if (mp[c].size()) {
          swap(s[pos], s[mp[c].back()]);
          solve(pos + 1, mp[c].back());
          return;
        }
      }
    }
  };
  solve(0, n);
  cout << s << "\n";
}