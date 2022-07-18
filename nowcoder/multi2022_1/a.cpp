#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  for (ll i = 0, x, r; i < n; i++) {
    cin >> x >> r;
    a[i] = {x - r, x + r};
  }
  sort(a.begin(), a.end());
  vector<pair<ll, ll>> nex;
  for (auto& [l, r] : a) {
    if (nex.size() != 0 && (nex.back().second >= l)) {
      nex.back().second = max(nex.back().second, r);
    } else {
      nex.push_back({l, r});
    }
  }
  ll res = 0;
  for (int i = 0; i < int(nex.size()) - 1; i++) {
    res += abs(nex[i].second - nex[i + 1].first);
  }
  cout << res << "\n";
}
