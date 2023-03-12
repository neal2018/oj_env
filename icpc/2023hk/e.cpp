#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  int n;
  vector<int> length, cnt, total;
  SegTree(int _n) : n(_n), length(2 * n), cnt(2 * n), total(2 * n) {
    for (int i = n; i < 2 * n; i++) total[i] = 1;
    for (int i = n - 1; i > 0; i--) total[i] = total[2 * i] + total[2 * i + 1];
  }
  void build(int x) {
    for (; x > 0; x /= 2) pushup(x);
  }
  void pushup(int x) {
    length[x] = (cnt[x] > 0 ? total[x] : (x < n ? length[x * 2] + length[x * 2 + 1] : 0));
  }
  void modify(int l, int r, int v) {
    int l0 = l + n, r0 = r + n;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) cnt[l] += v, pushup(l++);
      if (r & 1) cnt[--r] += v, pushup(r);
    }
    build(l0), build(r0 - 1);
  }
  int query(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += length[l++];
      if (r & 1) res += length[--r];
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  ll res = 0;
  SegTree seg(n);
  map<int, vector<int>> mp;
  map<int, array<int, 2>> prev;
  for (int i = 0; i < n; i++) {
    auto& v = mp[a[i]];
    v.push_back(i);
    if (v.size() == k) {
      seg.modify(0, v[0] + 1, 1);
      prev[a[i]] = {0, v[0] + 1};
    } else if (v.size() > k) {
      auto [pre_l, pre_r] = prev[a[i]];
      seg.modify(pre_l, pre_r, -1);
      int l = v.end()[-k - 1] + 1, r = v.end()[-k] + 1;
      seg.modify(l, r, 1);
      prev[a[i]] = {l, r};
    }
    // cout << "add " << prev[a[i]][0] << " " << prev[a[i]][1] << "\n";
    int invalid = seg.query(0, i + 1);
    res += i + 1 - invalid;
    // cout << i << " " << invalid << "\n";
  }
  cout << res << "\n";
}
