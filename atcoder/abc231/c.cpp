#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  for (int i = 0, x; i < q; i++) {
    cin >> x;
    auto it = upper_bound(a.begin(), a.end(), x-1);
    ll ans = n - (it - a.begin());
    cout << ans << '\n';
  }
}