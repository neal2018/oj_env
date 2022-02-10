#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  vector<pair<int, int>> res;
  ll cnt = 0;
  for (auto& c : s) {
    if (c == '<') {
      cnt--;
    } else if (c == '>') {
      cnt++;
    } else {
      res.push_back({(c - 'C' + 7) % 7 + 1, cnt});
    }
  }
  for (auto& [c, k] : res) {
    cout << c;
    if (k > 0) {
      cout << string(k, '*');
    } else if (k < 0) {
      cout << string(-k, '.');
    }
  }
  cout << "\n";
}
