#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (int n; T--;) {
    vector<int> a(7);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    cout << a[0] << " " << a[1] << " " << a[6] - a[0] - a[1] << '\n';
  }
}