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
    vector<int> seg_max(2 * n), seg_min(2 * n);
    for (int i = 0; i < n; i++) seg_max[i + n] = seg_min[i + n] = (int)a[i];
    for (int i = n - 1; i >= 0; i--) {
      seg_max[i] = max(seg_max[i * 2], seg_max[i * 2 + 1]);
      seg_min[i] = min(seg_min[i * 2], seg_min[i * 2 + 1]);
    }
    auto q_max = [&](int l, int r) {
      int res = 0;
      for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = max(res, seg_max[l++]);
        if (r & 1) res = max(res, seg_max[--r]);
      }
      return res;
    };
    auto q_min = [&](int l, int r) {
      int res = 1e9;
      for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res = min(res, seg_min[l++]);
        if (r & 1) res = min(res, seg_min[--r]);
      }
      return res;
    };
    set<ll> can;
    function<void(int, int)> dfs = [&](int left, int right) {
      // inclusive
      can.insert(pre[right + 1] - pre[left]);
      if (left >= right) return;
      ll maxi = q_max(left, right + 1);
      ll mini = q_min(left, right + 1);
      ll mid = (maxi + mini) / 2;
      int pos = (int)(upper_bound(a.begin(), a.end(), mid) - a.begin());
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