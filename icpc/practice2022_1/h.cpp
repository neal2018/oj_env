#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  constexpr ll week = 10080;
  ll l, m;
  cin >> l >> m;
  string s;
  getline(cin, s);
  ll price = 1e18;
  vector<string> res;
  for (int i = 0; i < m; i++) {
    getline(cin, s);
    stringstream ss(s);
    string tt;
    vector<string> cur;
    while (getline(ss, tt, ',')) {
      cur.push_back(tt);
    }
    assert(cur.size() == 5);
    ll p = stoll(cur[1]);
    ll c = stoll(cur[2]);
    ll t = stoll(cur[3]);
    ll r = stoll(cur[4]);
    if (c * t * week >= l * (t + r)) {
      if (p < price) {
        price = p;
        res.clear();
      }
      if (p == price) res.push_back(cur[0]);
    }
  }
  if (!res.size()) {
    cout << "no such mower\n";
  } else {
    for (auto& x : res) cout << x << "\n";
  }
}