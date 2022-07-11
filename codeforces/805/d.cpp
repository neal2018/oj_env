#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    string s;
    ll p;
    cin >> s >> p;
    map<char, vector<int>> mp;
    ll cur = 0;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]].push_back(i);
      cur += s[i] - 'a' + 1;
    }
    int c = 25;
    while (cur > p && c >= 0) {
      char cc = char(c + 'a');
      while (mp[cc].size() == 0) c--, cc = char(c + 'a');
      mp[cc].pop_back();
      cur -= c + 1;
    }
    vector<pair<int, char>> a;
    for (auto& [k, v] : mp) {
      for (auto& x : v) a.push_back({x, k});
    }
    sort(a.begin(), a.end());
    for (auto& [pos, cc] : a) cout << cc;
    cout << "\n";
  }
}
