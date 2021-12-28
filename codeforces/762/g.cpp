#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) { return p[x] == x ? x : (p[x] = find(p[x])); };
    auto merge = [&](int x, int y) { p[find(x)] = find(y); };
    map<int, set<pair<int, int>>> xxs, yys;
    for (int i = 0, x, y; i < n; i++) {
      cin >> x >> y >> t[i];
      auto &xs = xxs[y], &ys = yys[x];
      auto itx = xs.lower_bound({x, 0}), ity = ys.lower_bound({y, 0});
      if (itx != xs.end() && abs(itx->first - x) <= k) merge(i, itx->second);
      if (ity != ys.end() && abs(ity->first - y) <= k) merge(i, ity->second);
      if (itx != xs.begin() && abs((--itx)->first - x) <= k) merge(i, itx->second);
      if (ity != ys.begin() && abs((--ity)->first - y) <= k) merge(i, ity->second);
      xs.insert({x, i}), ys.insert({y, i});
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int r = find(i);
      if (mp.count(r) == 0) {
        mp[r] = t[i];
      } else {
        mp[r] = min(mp[r], t[i]);
      }
    }
    vector<int> mini;
    for (auto& [_, v] : mp) mini.push_back(v);
    ranges::sort(mini);
    int res = 0, sz = (int)mini.size();
    for (int l = 0; res < sz; res++) {
      while (l < sz && mini[l] <= res) l++;
      if (l + res + 1 >= sz - 1) break;
    }
    cout << res << "\n";
  }
}
