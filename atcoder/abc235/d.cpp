#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  auto rotate = [&](ll cur) {
    string s = to_string(cur);
    if (s.size() > 1 && s[1] != '0') {
      cur = stoll(s.substr(1) + s[0]);
    }
    return cur;
  };
  ll a, n, step = 0;
  cin >> a >> n;
  set<ll> seen{n};
  for (vector<ll> q{n}, nq; q.size(); swap(q, nq), nq.clear(), step++) {
    for (auto& x : q) {
      if (x == 1) {
        cout << step << "\n";
        return 0;
      }
      {
        ll t = rotate(x);
        if (seen.count(t) == 0) {
          seen.insert(t);
          nq.push_back(t);
        }
      }
      if (x % a == 0) {
        ll t = x / a;
        if (seen.count(t) == 0) {
          seen.insert(t);
          nq.push_back(t);
        }
      }
    }
  }
  cout << -1 << '\n';
}