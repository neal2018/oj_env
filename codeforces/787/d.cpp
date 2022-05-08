#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    vector<int> a(n), seen(n), is_leaf(n, 1);
    for (auto& x : a) cin >> x, x--, is_leaf[x] = 0;
    if (n == 1) {
      cout << "1\n1\n1\n\n";
      continue;
    }
    vector<vector<ll>> res;
    for (int i = 0; i < n; i++) {
      if (is_leaf[i]) {
        int cur = i;
        vector<ll> temp;
        while (seen[cur] == 0) {
          seen[cur] = 1;
          temp.push_back(cur);
          cur = a[cur];
        }
        reverse(temp.begin(), temp.end());
        res.push_back(temp);
      }
    }
    cout << res.size() << "\n";
    for (auto& v : res) {
      cout << v.size() << '\n';
      for (auto& x : v) cout << x + 1 << " ";
      cout << "\n";
    }
    cout << "\n";
  }
}
