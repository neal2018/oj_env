#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<ll> a(n), b(n);
    unordered_map<ll, ll> aa, bb;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      aa[a[i]]++, bb[b[i]]++;
    }
    ll cn3 = n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++) {
      cn3 -= (aa[a[i]] - 1) * (bb[b[i]] - 1);
    }
    cout << cn3 << '\n';
  }
}