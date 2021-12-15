#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    ll sum = 0;
    for (int i = 0; i < n - 2 * k; i++) sum += a[i];
    for (int i = n - 2 * k; i < n - k; i++) sum += a[i] / a[i + k];
    cout << sum << '\n';
  }
}