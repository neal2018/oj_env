#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr i64 inf = 1e18;

struct SegTree {
  i64 n;
  std::vector<int> t;
  SegTree(i64 _n) : n(_n), t(2 * n) {}
  void modify(i64 p, int v) {
    t[p += n] += v;
    for (p /= 2; p; p /= 2) t[p] = t[2 * p] + t[2 * p + 1];
  }
  int query(i64 l, i64 r) {
    int res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) res += t[l++];
      if (r & 1) res += t[--r];
    }
    return res;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<std::vector<int>> update(m);
  for (int i = 0; auto x : a) {
    update[x].push_back(i);
    i++;
  }
  i64 res = 0;
  SegTree seg(m);
  for (auto x : a) {
    res += seg.query(x + 1, m);
    seg.modify(x, 1);
  }

  std::cout << res << "\n";
  for (int i = m - 1; i > 0; i--) {
    auto& need = update[i];
    for (int cnt = 0; cnt < need.size(); cnt++) {
      auto index = need[cnt];
      res += (index - cnt) - (n - index - 1 - (i64(need.size()) - 1 - cnt));
    }
    std::cout << res << "\n";
  }
}
