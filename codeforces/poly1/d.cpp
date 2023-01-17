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
    vector a(n, vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
    }
    vector<array<int, 2>> ones(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
      int cnt = int(count(a[i].begin(), a[i].end(), 1));
      total += cnt;
      ones[i] = {i, cnt};
    }
    if (total % n != 0) {
      cout << "-1\n";
      continue;
    }
    int need = total / n;
    vector<array<int, 3>> res;
    partition(ones.begin(), ones.end(), [&](const auto& x) { return x[1] < need; });
    for (int i = 0, j = n - 1; i < j;) {
      for (int k = 0; k < m && ones[i][1] < need && ones[j][1] > need; k++) {
        if (a[ones[i][0]][k] == 0 && a[ones[j][0]][k] == 1) {
          swap(a[ones[i][0]][k], a[ones[j][0]][k]);
          ones[i][1]++, ones[j][1]--;
          res.push_back({ones[i][0], ones[j][0], k});
        }
      }
      if (ones[i][1] == need) i++;
      if (ones[j][1] == need) j--;
    }
    cout << res.size() << "\n";
    for (auto& [x, y, z] : res) {
      cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
    }
  }
}
