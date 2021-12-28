#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> p(n), pp(n), r(n);
  for (auto& x : p) cin >> x, x--;
  int N = (int)sqrt(n) + 1;
  for (int i = 0; i < n; i++) {
    pp[i] = i;
    for (int j = 0; j < N; j++) pp[i] = p[pp[i]];
  }
  for (int i = 0; i < n; i++) r[p[i]] = i;
  for (int op, x, y; q--;) {
    cin >> op >> x >> y;
    if (op == 1) {
      x--, y--;
      swap(p[x], p[y]);
      swap(r[p[x]], r[p[y]]);
      for (int t : {x, y}) {
        int tt = t;
        for (int i = 0; i < N; i++) t = p[t];
        for (int i = 0; i < N; i++) {
          pp[tt] = t, tt = r[tt], t = r[t];
        }
      }
    } else {
      x--;
      int res = x;
      while (y >= N) y -= N, res = pp[res];
      while (y >= 1) y--, res = p[res];
      cout << res + 1 << '\n';
    }
  }
}
