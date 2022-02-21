#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

constexpr ld eps = 1e-9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;
  while (T--) {
    ld c, m, p, v;
    cin >> c >> m >> p >> v;
    function<ld(ld, ld)> dfs2;
    function<ld(ld, ld, ld)> dfs = [&](ld cc, ld mm, ld pp) {
      ld res = pp;
      if (cc > v + eps) {
        res += cc * (dfs(cc - v, mm + v / 2, pp + v / 2) + 1);
      } else {
        res += cc * (dfs2(mm + cc / 2, pp + cc / 2) + 1);
      }
      if (mm > v + eps) {
        res += mm * (dfs(cc + v / 2, mm - v, pp + v / 2) + 1);
      } else {
        res += mm * (dfs2(cc + mm / 2, pp + mm / 2) + 1);
      }
      return res;
    };
    dfs2 = [&](ld cc, ld pp) {
      ld res = pp;
      if (cc > v + eps) {
        res += cc * (dfs2(cc - v, pp + v) + 1);
      } else {
        res += cc * 2;
      }
      return res;
    };
    cout << dfs(c, m, p) << "\n";
  }
}
