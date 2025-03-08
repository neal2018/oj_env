#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int inf = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<i64> b(n), w(m);
  for (auto& x : b) std::cin >> x;
  for (auto& x : w) std::cin >> x;
  std::sort(b.begin(), b.end(), std::greater());
  std::sort(w.begin(), w.end(), std::greater());

  i64 res = 0;
  int cnt_i = 0, cnt_j = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] > 0) {
      res += b[i];
      cnt_i++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (w[i] > 0 && cnt_j < cnt_i) {
      res += w[i];
      cnt_j++;
    } else if (w[i] > 0) {
      if (cnt_i < n && b[cnt_i] + w[i] > 0) {
        res += b[cnt_i] + w[i];
        cnt_i++, cnt_j++;
      }
    }
  }
  std::cout << res << "\n";
}
