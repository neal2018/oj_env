#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, maxi = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x, maxi = max(maxi, x);
  vector<array<int, 3>> qs(m);
  for (int i = 0; i < m; i++) {
    auto &[x, y, z] = qs[i];
    cin >> x >> y, x--, z = i;
  }
  int SIZE = max(1, (int)(n / sqrt(m)));
  sort(qs.begin(), qs.end(), [&](auto &x, auto &y) {
    return pair{x[0] / SIZE, x[1]} < pair{y[0] / SIZE, y[1]};
  });
  vector<int> seen(maxi + 1);
  vector<int> res(m);
  int cur = 0;
  auto add = [&](int x) {
    cur -= (seen[x] % 2);
    seen[x]++;
    cur += (seen[x] % 2);
  };
  auto del = [&](int x) {
    cur -= (seen[x] % 2);
    seen[x]--;
    cur += (seen[x] % 2);
  };
  int L = 0, R = 0;  //  store [L, R)
  for (auto &[l, r, id] : qs) {
    while (L > l) add(a[--L]);
    while (R < r) add(a[R++]);
    while (L < l) del(a[L++]);
    while (R > r) del(a[--R]);
    res[id] = cur != 0;
  }
  for (auto &x : res) cout << (x ? "Alice\n" : "Bob\n");
}
