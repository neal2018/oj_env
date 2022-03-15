#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll n, x;
  string s;
  cin >> n >> x >> s;
  vector<int> pos;
  while (x) {
    pos.push_back(x % 2), x /= 2;
  }
  reverse(pos.begin(), pos.end());
  for (auto& c : s) {
    if (c == 'U') {
      pos.pop_back();
    } else if (c == 'L') {
      pos.push_back(0);
    } else {
      pos.push_back(1);
    }
  }
  ll res = 0;
  for (auto& p : pos) {
    res = res * 2 + p;
  }
  cout << res << "\n";
}
