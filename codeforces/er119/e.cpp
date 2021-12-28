#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int q, MAX = 5e5 + 10, cur = MAX;
  cin >> q;
  vector<int> p(MAX * 3), mp(MAX * 3);
  iota(p.begin(), p.end(), 0);
  iota(mp.begin(), mp.end(), 0);
  map<int, int> inv;
  function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
  auto merge = [&](int x, int y) { p[find(x)] = find(y); };
  vector<int> res;
  res.reserve(1e5);
  for (int i = 0, x, y, op; i < q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      if (find(mp[x]) != mp[x]) mp[x] = ++cur;
      inv[mp[x]] = x;
      res.push_back(mp[x]);
    } else {
      cin >> x >> y;
      if (find(mp[y]) != mp[y]) mp[y] = ++cur;
      merge(mp[x], mp[y]);
      if (find(mp[x]) != mp[x]) mp[x] = ++cur;
      inv[mp[x]] = x, inv[mp[y]] = y;
    }
  }
  for (auto& x : res) cout << inv[find(x)] << ' ';
  cout << '\n';
}
