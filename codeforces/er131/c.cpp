#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0, x; i < m; i++) cin >> x, x--, a[x]++;
    auto check = [&](int mid) {
      vector<int> worker(n, mid);
      int remain = 0;
      for (int i = 0; i < n; i++) {
        int sub = min(worker[i], a[i]);
        worker[i] -= sub;
        remain += a[i] - sub;
      }
      for (int i = 0; i < n && remain > 0; i++) {
        remain -= worker[i] / 2;
      }
      return remain <= 0;
    };
    int l = 1, r = 1e9;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << r << "\n";
  }
}
