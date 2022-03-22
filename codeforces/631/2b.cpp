#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, x--;
    ll maxi = *max_element(a.begin(), a.end());
    vector<int> cnt(maxi + 1);
    for (auto& x : a) cnt[x]++;
    int pos = -1;
    while (pos < maxi && cnt[pos + 1] == 2) pos++;
    {
      int f = (pos >= 0);
      for (int i = pos + 1; i <= maxi; i++) {
        if (cnt[i] != 1) f = 0;
      }
      if (!f) {
        cout << "0\n";
        continue;
      }
    }
    set<pair<int, int>> res;
    for (auto k : {pos + 1, n - 1 - pos}) {
      vector<int> seen(n);
      for (int i = 0; i < k; i++) {
        seen[a[i]] = 1;
      }
      if (accumulate(seen.begin(), seen.begin() + k, 0ll) == k) {
        res.insert({k, n - k});
      }
    }
    cout << res.size() << "\n";
    for (auto& [l, r] : res) cout << l << " " << r << "\n";
  }
}
