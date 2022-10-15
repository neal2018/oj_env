#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<set<int>> row(n, {-1, m}), col(m, {-1, n});
  int rs, cs;
  cin >> rs >> cs, rs--, cs--;
  int k;
  cin >> k;
  while (k--) {
    int x, y;
    cin >> x >> y, x--, y--;
    row[x].insert(y), col[y].insert(x);
  }
  int q;
  cin >> q;
  while (q--) {
    char d;
    int l;
    cin >> d >> l;
    if (d == 'L') {
      auto t = --row[rs].upper_bound(cs);
      cs = max(*t + 1, cs - l);
    } else if (d == 'R') {
      auto t = row[rs].upper_bound(cs);
      cs = min(*t - 1, cs + l);
    } else if (d == 'U') {
      auto t = --col[cs].upper_bound(rs);
      rs = max(*t + 1, rs - l);
    } else {
      auto t = col[cs].upper_bound(rs);
      rs = min(*t - 1, rs + l);
    }
    cout << rs + 1 << " " << cs + 1 << "\n";
  }
}
