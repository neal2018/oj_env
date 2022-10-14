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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> res;
    res.reserve(n);
    map<int, int> mp;
    int total = 0;
    while (a.size()) {
      sort(a.begin(), a.end(), [&](int x, int y) { return (x & (~total)) > (y & (~total)); });
      res.push_back(a[0]);
      total |= a[0];
      vector<int> b;
      for (int i = 1; i < a.size(); i++) {
        auto x = (a[i] & (~total));
        auto pre_x = (a[i - 1] & (~total));
        if (x != pre_x) {
          b.push_back(a[i]);
        } else {
          mp[a[i]]++;
        }
      }
      a = b;
    }
    for (auto [k, v] : mp) {
      while (v--) res.push_back(k);
    }
    for (auto& x : res) cout << x << " ";
    cout << "\n";
  }
}
