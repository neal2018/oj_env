#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;

  auto get_power10 = [&](auto i) {
    i64 res = 1;
    while (i--) {
      res *= 10;
    }
    return res;
  };

  for (int case_no = 1; case_no <= T; case_no++) {
    i64 A, B, m;
    std::cin >> A >> B >> m;

    auto solve = [&](i64 x) {
      if (x < 0) {
        return i64(0);
      }
      vector<i64> a;
      while (x) a.push_back(x % 10), x /= 10;
      reverse(a.begin(), a.end());
      int n = int(a.size());

      i64 ans = 0;

      for (int mid = 0; 2 * mid + 1 <= n; mid++) {
        auto memo = std::vector(30, std::vector(20, std::map<i64, i64>{}));
        function<i64(i64, i64, i64, i64)> dfs = [&](i64 cur, i64 pre, i64 sum, i64 limit) {
          auto &vv = memo[cur][pre + 1][sum];
          if (limit == 0 && vv != 0) return vv - 1;

          i64 res = 0;
          if (cur == 2 * mid + 1) {
            res = (sum % m == 0);
          } else {
            i64 maxi = (limit ? a[cur] : 9);
            i64 mini = 1;
            if (cur < mid) {
              mini = std::max(i64(1), pre);
            } else if (cur == mid) {
              mini = pre + 1;
            } else {
              maxi = std::min(maxi, (cur == mid + 1) ? pre - 1 : pre);
            }

            for (i64 i = mini; i <= maxi; i++) {
              i64 new_sum = (get_power10(2 * mid - cur) * i % m + sum) % m;
              res += dfs(cur + 1, i, new_sum, limit && (i == a[cur]));
            }
          }
          if (limit != 1) {
            vv = res + 1;
          }
          // std::cout << cur << "\t" << pre << "\t" << sum << "\t" << limit << "\t" << mid << "\t"
          //           << res << "\n";
          return res;
        };
        ans += dfs(0, 0, 0, 2 * mid + 1 == n);
      }
      // std::cout << "solve " << x << " " << ans << "\n";
      return ans;
    };

    auto res = solve(B) - solve(A - 1);
    std::cout << "Case #" << case_no << ": ";
    std::cout << res << "\n";
  }
}
