#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie()->sync_with_stdio(false);
  int n, m, threshold = 550, running = 0;
  cin >> n >> m;
  vector<int> x(n), y(n), a(n), p(3e5);
  vector bucket(threshold, vector<int>(threshold));
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0, op, k; i < m; i++) {
    cin >> op >> k, k--;
    int sum = x[k] + y[k], res = 0;
    if (op == 1) {
      a[k] = i;
      if (sum < threshold) {
        for (int j = 0; j < sum; j++) {
          bucket[sum][(i + j) % sum] += (j >= x[k]);
        }
      } else {
        for (int j = i + x[k]; j < m; j += sum) {
          p[j]++, p[j + y[k]]--;
        }
      }
    } else {
      if (sum < threshold) {
        for (int j = 0; j < sum; j++) {
          bucket[sum][(a[k] + j) % sum] -= (j >= x[k]);
        }
      } else {
        for (int j = a[k] + x[k]; j < m; j += sum) {
          if (j >= i) p[j]--;
          if (j + y[k] >= i) p[j + y[k]]++;
        }
      }
    }
    running += p[i];
    for (int j = 2; j < threshold; j++) res += bucket[j][i % j];
    cout << res + running << '\n';
  }
}