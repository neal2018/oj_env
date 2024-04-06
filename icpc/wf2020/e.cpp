#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<i64> d(n + 1);
  std::vector<i64> d2(n + 2);
  // add ap
  // a[i] + 1, a[i+1] + 2, ..., a[j-1] + (j-i), a[j]
  // diff:
  // d[i] = a[i] - a[i-1]
  // d[i] + 1, d[i+1] + 1, ..., d[j-1] + 1, d[j] - (j - i)

  auto range_add = [&](std::vector<i64>& diff, int x1, int x2, i64 val) {
    diff[x1] += val, diff[x2] -= val;
  };

  auto range_add_ap = [&](std::vector<i64>& diff2, int x1, int x2, i64 val) {
    range_add(diff2, x1, x2, val);
    range_add(diff2, x2, x2 + 1, -val * (x2 - x1));
  };

  while (q--) {
    char c;
    int x1, x2;
    std::cin >> c >> x1 >> x2, x1--;
    if (c == 'R') {
      d[x1]++, d[x2]--;
    } else if (c == 'D') {
      d[x1]--, d[x2]++;
    } else {
      int val = (c == 'H') ? 1 : -1;
      if ((x2 - x1) % 2 == 0) {
        // 0, 1, 2, 3, 4, 5
        //    1  2  2  1
        int len = (x2 - x1) / 2;
        range_add_ap(d2, x1, x1 + len, val);
        range_add(d, x1 + len, x2, val * (len + 1));
        range_add_ap(d2, x1 + len, x2, -val);
      } else {
        // 1, 1, 2, 3, 4, 5, 6
        //    1  2  3, 2  1
        int len = (x2 - x1) / 2;
        range_add_ap(d2, x1, x1 + len, val);
        range_add(d, x1 + len, x2, val * (len + 1));
        range_add_ap(d2, x1 + len + 1, x2, -val);
      }
    }
  }
  for (int i = 1; i < n; i++) d[i] += d[i - 1];
  for (int i = 1; i < n; i++) d2[i] += d2[i - 1];
  for (int i = 1; i < n; i++) d2[i] += d2[i - 1];
  for (int i = 0; i < n; i++) {
    std::cout << d[i] + d2[i] << "\n";
  }
}
