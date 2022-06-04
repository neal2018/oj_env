#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<array<int, 3>> segments(n);
    for (auto& [u, v, c] : segments) cin >> c >> u >> v, u--, v--;
    sort(segments.begin(), segments.end());

    vector<ll> p(n);
    iota(p.begin(), p.end(), 0);
    function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
    auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };

    vector<vector<int>> passed(2);
    int cur = 0;
    for (auto& [u, v, c] : segments) {
      auto &my = passed[c], &another = passed[!c];
      int save = -1;
      for (auto& id : another) {
        if (segments[id][1] >= u) {
          merge(id, cur);
          if (save == -1 || segments[id][1] >= segments[save][1]) save = id;
        }
      }
      another = (save == -1 ? vector<int>{} : vector<int>{save});
      my.push_back(cur);
      cur++;
    }
    vector<int> total(n);
    for (auto i : views::iota(0, n)) total[i] = find(i);
    sort(total.begin(), total.end());
    total.erase(unique(total.begin(), total.end()), total.end());
    cout << total.size() << "\n";
  }
}
