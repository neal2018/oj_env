#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
const ll MOD = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> h(n);
    for (auto& x : h) cin >> x;
    ranges::sort(h);
    ll diff = abs(h[0] - h[n - 1]);
    int index = -1;
    for (int i = 0; i < n - 1; i++) {
      ll cur = h[i + 1] - h[i];
      if (cur < diff) {
        diff = cur;
        index = i;
      }
    }
    if (index != -1) {
      vector<ll> a;
      for (int i = index + 1; i < n; i++) a.push_back(h[i]);
      for (int i = 0; i <= index; i++) a.push_back(h[i]);
      h = a;
    }
    for (auto& x : h) cout << x << " ";
    cout << '\n';
  }
}