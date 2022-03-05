#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, maxi = 0;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x, maxi = max(maxi, x);
  cin >> m;
  vector<tuple<int, int, int>> qs(m);
  for (int i = 0; i < m; i++) {
    auto &[x, y, z] = qs[i];
    cin >> x >> y, x--, z = i;
  }
  int SIZE = max(1, (int)(n / sqrt(m)));
  sort(qs.begin(), qs.end(), [&](auto &x, auto &y) {
    auto &[lx, rx, ix] = x;
    auto &[ly, ry, iy] = y;
    return lx / SIZE == ly / SIZE ? rx < ry : lx / SIZE < ly / SIZE;
  });
  vector<int> seen(maxi + 1);
  vector<ll> res(m);
  ll cur = 0;
  auto add = [&](int x) {
    cur -= seen[x] / 2;
    seen[x]++;
    cur += seen[x] / 2;
  };
  auto del = [&](int x) {
    cur -= seen[x] / 2;
    seen[x]--;
    cur += seen[x] / 2;
  };
  int L = 0, R = 0;  //  store [L, R)
  for (auto &[l, r, id] : qs) {
    while (L > l) add(a[--L]);
    while (R < r) add(a[R++]);
    while (L < l) del(a[L++]);
    while (R > r) del(a[--R]);
    res[id] = cur;
  }
  for (auto &x : res) cout << x << "\n";
}
