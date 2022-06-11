#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
      auto f = [&] {
        vector<int> p(n + 30);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) { return x == p[x] ? x : (p[x] = find(p[x])); };
        auto merge = [&](int x, int y) { p[find(x)] = find(y); };
        for (auto i : views::iota(0, n)) {
          for (auto t : views::iota(0, 30)) {
            if (a[i] & (1 << t)) merge(i, n + t);
          }
        }
        vector<int> weight(n + 30);
        for (auto i : views::iota(0, n)) weight[find(i)]++;
        return ranges::max(weight) == n;
      };
      if (f()) return;
      res++;
      for (auto i : views::iota(0, n)) {
        if (a[i]--; f()) return;
        if (a[i] += 2; f()) return;
        a[i]--;
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
