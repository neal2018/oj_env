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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    for (auto& x : a)
      if (x & 1) cout << x << " ";
    for (auto& x : a)
      if ((x & 1) == 0) cout << x << " ";
    cout << '\n';
  }
}