#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto func = [&]() {
    // s -> t
    string s, t, p;
    cin >> s >> t >> p;
    if (s == t) return true;
    if (s.size() >= t.size()) return false;
    vector<int> save(26);
    for (auto& c : p) save[c - 'a']++;
    int i = 0, j = 0;
    for (; i < s.size() && j < t.size();) {
      if (s[i] == t[j]) {
        i++, j++;
      } else {
        if (save[t[j] - 'a'] == 0) return false;
        save[t[j] - 'a']--, j++;
      }
    }
    if (i != s.size()) return false;
    for (; j < t.size();) {
      if (save[t[j] - 'a'] == 0) return false;
      save[t[j] - 'a']--, j++;
    }
    return true;
  };
  while (T--) {
    cout << (func() ? "YES\n" : "NO\n");
  };
}
