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
    map<int, vector<int>> mp;
    for (int i = 0, x; i < n; i++) cin >> x, mp[x].push_back(i);
    if (any_of(mp.begin(), mp.end(), [&](auto& t) { return t.second.size() == 1; })) {
      cout << "-1\n";
    } else {
      vector<int> res(n);
      for (auto& [k, v] : mp) {
        for (int i = 0; i < v.size(); i++) res[v[i]] = v[(i + 1) % v.size()];
      }
      for (auto& x : res) cout << x + 1 << " ";
      cout << "\n";
    }
  }
}