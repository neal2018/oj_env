#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  // n = 1e5;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  // for (auto& x : a) x = 1e9;
  sort(a.begin(), a.end());
  auto poss = a[0];
  for (int i = 1; i < n; i++) {
    if (poss != -1) {
      if (poss > a[i] / 2 && poss != a[i]) poss = -1;
    }
  }
  auto res = a[0] / 2;
  if (poss != -1) {
    res = max(res, poss);
  }
  cout << res << "\n";
}
