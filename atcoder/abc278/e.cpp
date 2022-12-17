#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, maxi, h, w;
  cin >> n >> m >> maxi >> h >> w;
  vector<int> freq_all(maxi);
  int cnt_all = 0;
  vector a(n, vector<int>(m));
  for (auto& r : a) {
    for (auto& x : r) {
      cin >> x, x--;
      freq_all[x]++;
      if (freq_all[x] == 1) cnt_all++;
    }
  }
  vector<vector<int>> res(n - h + 1, vector<int>(m - w + 1));
  for (int i = 0; i <= n - h; i++) {
    auto freq = freq_all;
    int cnt = cnt_all;
    auto add = [&](int x) {
      freq[x]++;
      if (freq[x] == 1) cnt++;
    };
    auto remove = [&](int x) {
      freq[x]--;
      if (freq[x] == 0) cnt--;
    };
    for (int ii = i; ii < i + h; ii++) {
      for (int jj = 0; jj < w; jj++) {
        remove(a[ii][jj]);
      }
    }
    for (int j = 0; j <= m - w; j++) {
      res[i][j] = cnt;
      for (int ii = i; ii < i + h; ii++) {
        add(a[ii][j]);
      }
      if (j != m - w) {
        for (int ii = i; ii < i + h; ii++) {
          remove(a[ii][j + w]);
        }
      }
    }
  }
  for (auto& r : res) {
    for (auto& x : r) {
      cout << x << " ";
    }
    cout << "\n";
  }
}
