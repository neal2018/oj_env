#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), occ(n);
  for (auto& x : a) cin >> x, x--;
  for (int i = 0; i < n; i++) occ[a[i]] = i;
  int last = 0, res = 0, can = 0;
  for (int i = 0; i < n; i++) {
    can = max(can, occ[a[i]]);
    if (i < last) {
      res++;
    } else {
      last = max(last, can);
    }
  }
  cout << res << "\n";
}