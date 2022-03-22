#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto& c : s) mp[c]++;
    for (int i = 0; i < s.size(); i++) {
      if (mp[s[i]] == 1) {
        cout << s.substr(i) << "\n";
        break;
      } else {
        mp[s[i]]--;
      }
    }
  }
}
