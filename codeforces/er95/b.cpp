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
    vector<int> a(n), unlocks;
    for (auto& x : a) cin >> x;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (!x) unlocks.push_back(i);
    }
    auto copy = unlocks;
    auto ori = a;
    sort(copy.begin(), copy.end(), [&](int x, int y) { return a[x] > a[y]; });
    for (int i = 0; i < unlocks.size(); i++) {
      a[unlocks[i]] = ori[copy[i]];
    }
    for (auto& x : a) cout << x << " ";
    cout << "\n";
  }
}
