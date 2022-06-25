#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  set<pair<int, int>> st;
  {
    for (auto l : views::iota(0, n - 1)) {
      int cur = a[l + 1];
      int maxi = 1;
      while (maxi <= a[l]) maxi *= 2;
      for (auto r : views::iota(l + 2, n)) {
        if (cur == (a[l] ^ a[r])) st.emplace(l, r);
        cur += a[r];
        if (cur > maxi) break;
      }
    }
  }
  basic_string<int> s;
  {
    reverse(a.begin(), a.end());
    for (auto l : views::iota(0, n - 1)) {
      int cur = a[l + 1];
      int maxi = 1;
      while (maxi <= a[l]) maxi *= 2;
      for (auto r : views::iota(l + 2, n)) {
        if (cur == (a[l] ^ a[r])) st.emplace(n - 1 - r, n - 1 - l);
        cur += a[r];
        if (cur > maxi) break;
      }
    }
  }
  cout << st.size() << "\n";
}
