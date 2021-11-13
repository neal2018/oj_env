#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, q;
  ll s;
  cin >> T;
  while (T--) {
    cin >> n >> q;
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    ranges::sort(a);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
    set<ll> can;
    function<void(int, int)> dfs = [&](int left, int right) {
      // inclusive
      can.insert(pre[right + 1] - pre[left]);
      if (left >= right) return;
      ll mid = (a[left] + a[right]) / 2;
      int pos = (int)(ranges::upper_bound(a, mid) - a.begin());
      // [left, pos) ,  [pos, right]
      if (pos <= left || pos > right) return;
      dfs(left, pos - 1), dfs(pos, right);
    };
    dfs(0, n - 1);
    for (int i = 0; i < q; i++) {
      cin >> s;
      if (can.count(s)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}