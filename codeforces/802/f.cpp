#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector a(2, vector<int>(n)), b(2, vector<int>(n));
  int sum_a = 0, sum_b = 0;
  for (auto& r : a) {
    for (auto& x : r) cin >> x, sum_a += x;
  }
  for (auto& r : b) {
    for (auto& x : r) cin >> x, sum_b += x;
  }
  if (sum_a != sum_b) {
    cout << "-1\n";
    return 0;
  }
  ll res = 0;
  int p[2] = {}, q[2] = {};
  auto dec = [](int& x, int& y) {
    int mini = min(x, y);
    x -= mini, y -= mini;
    return mini;
  };
  for (int i = 0; i < n; i++) {
    for (auto t : {0, 1}) {
      p[t] += a[t][i], q[t] += b[t][i];
      dec(p[t], q[t]);
    }
    for (auto t : {0, 1}) {
      if (p[t] && q[!t]) res += dec(p[t], q[!t]);
    }
    res += p[0] + p[1] + q[0] + q[1];
  }
  cout << res << "\n";
}
