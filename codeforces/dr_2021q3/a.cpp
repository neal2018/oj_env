#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (int n; T--;) {
    cin >> n;
    vector<ll> a(n);
    int cnt = 0;
    for (auto& x : a) {
      cin >> x;
      while (x % 2 == 0) cnt++, x /= 2;
    }
    ranges::sort(a, greater());
    a[0] <<= cnt;
    cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
  }
}