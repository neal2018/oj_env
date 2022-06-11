#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int SZ = 30;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, x == 0 && (res++, x++);
    [&] {
      vector g(SZ, vector<int>(SZ));
      auto f = [&] {
        int need = 0;
        for (auto i : views::iota(0, SZ)) need += (g[i][i] != 0);
        vector<ll> p(SZ);
        iota(p.begin(), p.end(), 0);
        function<ll(ll)> find = [&](ll x) { return x == p[x] ? x : (p[x] = find(p[x])); };
        auto merge = [&](ll x, ll y) { p[find(x)] = find(y); };
        for (auto i : views::iota(0, SZ)) {
          for (auto j : views::iota(i, SZ)) {
            if (g[i][j] && (find(i) != find(j))) merge(i, j), need--;
          }
        }
        return need == 1;
      };
      auto update = [&](int old, int cur) {
        for (auto i : views::iota(0, SZ)) {
          for (auto j : views::iota(i, SZ)) {
            g[i][j] -= (old & (1 << i)) && (old & (1 << j));
            g[i][j] += (cur & (1 << i)) && (cur & (1 << j));
          }
        }
      };
      for (auto& x : a) update(0, x);
      if (f()) return;
      res++;
      for (auto i : views::iota(0, n)) {
        if (update(a[i], a[i] - 1), a[i]--; a[i] != 0 && f()) return;
        if (update(a[i], a[i] + 2), a[i] += 2; f()) return;
        update(a[i], a[i] - 1), a[i]--;
      }
      vector<int> order(n);
      iota(order.begin(), order.end(), 0);
      sort(order.begin(), order.end(),
           [&](int x, int y) { return (a[x] & -a[x]) > (a[y] & -a[y]); });
      a[order[0]]--, a[order[1]]++, res++;
    }();
    cout << res << "\n";
    for (auto& x : a) cout << x << " ";
    cout << "\n";
    continue;
  }
}
