#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin>>T;
  for (int n, l, r, k; T--;) {
    cin >> n >> l >> r >> k;
    vector<int> a;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (x >= l && x <= r) a.push_back(x);
    }
    ranges::sort(a);
    int cnt = 0;
    for (auto& x : a) {
      if (x <= k) k -= x, cnt++;
    }
    cout << cnt << '\n';
  }
}