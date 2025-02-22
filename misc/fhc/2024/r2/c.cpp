#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;

  for (int case_no = 1; case_no <= T; case_no++) {
    int n, m;
    i64 k;
    std::cin >> n >> m >> k;
    std::vector a(n, std::vector<int>(m));
    for (auto& r : a) {
      for (auto& x : r) std::cin >> x;
    }

    int max_nm = std::max(n, m);
    std::vector<i64> res(max_nm * 2);

    for (int t = max_nm; t > 0; t--) {
      // horizontal
      for (int j = 0; j < m; j++) {
        std::map<int, int> freq;
        int cnt = 0;
        auto add = [&](int x) {
          if (x < n && j + t < m) {
            freq[a[x][j + t]]++;
            cnt++;
          }
          if (x < n && j - t >= 0) {
            freq[a[x][j - t]]++;
            cnt++;
          }
        };

        auto remove = [&](int x) {
          if (0 <= x && x < n && j + t < m) {
            freq[a[x][j + t]]--;
            cnt--;
          }
          if (0 <= x && x < n && j - t >= 0) {
            freq[a[x][j - t]]--;
            cnt--;
          }
        };
        for (int i = 0; i < t; i++) {
          add(i);
        }

        for (int i = 0; i < n; i++) {
          // include edges
          add(i + t);
          remove(i - 1 - t);
          res[t] += (cnt - freq[a[i][j]]);
        }
      }

      // vertical
      for (int i = 0; i < n; i++) {
        std::map<int, int> freq;
        int cnt = 0;
        auto add = [&](int x) {
          if (x < m && i + t < n) {
            freq[a[i + t][x]]++;
            cnt++;
          }
          if (x < m && i - t >= 0) {
            freq[a[i - t][x]]++;
            cnt++;
          }
        };

        auto remove = [&](int x) {
          if (0 <= x && x < m && i + t < n) {
            freq[a[i + t][x]]--;
            cnt--;
          }
          if (0 <= x && x < m && i - t >= 0) {
            freq[a[i - t][x]]--;
            cnt--;
          }
        };
        for (int j = 0; j < t - 1; j++) {
          add(j);
        }

        for (int j = 0; j < m; j++) {
          // include edges
          add(j - 1 + t);
          remove(j - t);
          res[t] += (cnt - freq[a[i][j]]);
        }
      }
    }

    std::cout << "Case #" << case_no << ": ";

    for (int t = 0; t <= max_nm; t++) {
      if (k <= res[t]) {
        std::cout << t << "\n";
      } else {
        k -= res[t];
      }
    }
  }
}
