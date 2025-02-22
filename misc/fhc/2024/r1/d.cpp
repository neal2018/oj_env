#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;

constexpr int MAX_N = 2e7;

constexpr int MOD = 998244353;
int power(int, i64) = delete;
template <typename T>
T power(T a, i64 b, int _MOD = MOD, T res = 1) {
  for (; b; b /= 2, (a *= a) %= _MOD)
    if (b & 1) (res *= a) %= _MOD;
  return res;
}
struct Z {
  int x;
  Z(int _x = 0) : x(norm(_x)) {}
  Z(long long _x) : x(norm(int((_x % MOD + MOD) % MOD))) {}
  static int norm(int x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
  }
  auto operator<=>(const Z &) const = default;  // need c++ 20
  Z operator-() const { return Z(norm(MOD - x)); }
  Z inv() const { return power(*this, MOD - 2, MOD); }
  Z &operator*=(const Z &rhs) { return x = int(i64(x) * rhs.x % MOD), *this; }
  Z &operator+=(const Z &rhs) { return x = norm(x + rhs.x), *this; }
  Z &operator-=(const Z &rhs) { return x = norm(x - rhs.x), *this; }
  Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }
  Z &operator%=(const int &rhs) { return x %= rhs, *this; }
  friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
  friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
  friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
  friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
  friend Z operator%(Z lhs, const int &rhs) { return lhs %= rhs; }
  friend auto &operator>>(std::istream &i, Z &z) { return i >> z.x; }
  friend auto &operator<<(std::ostream &o, const Z &z) { return o << z.x; }
};

i64 count(const string &s) {
  int n = int(s.size());
  vector<i64> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] != '0') dp[i] = dp[i - 1];
    if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }
  return dp[n];
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  std::cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    std::string s;
    // for (int i = 0; i < 10; i++) s += '?';
    // std::cout << s << "\n";
    std::cin >> s;

    i64 k;
    std::cin >> k;

    // if last == '?' or last == cur:
    //   dp[i][cur] = max(
    //      ((c == 1 || (c == 2 && cur <=6))? max(dp[i-2][cc]) : 0) + (cur != 0? dp[i-1][c] : 0)
    //   )
    // else dp[i][last] = -1

    using type = __float128;

    int n = int(s.size());
    std::vector<std::vector<std::vector<int>>> g(n, std::vector<std::vector<int>>(10));
    std::vector<std::vector<type>> dp(n, std::vector<type>(10));

    if (s[0] == '?') {
      for (int cur = 1; cur < 10; cur++) {
        dp[0][cur] = 1;
      }
    } else {
      if (s[0] != '0') {
        dp[0][s[0] - '0'] = 1;
      }
    }

    for (int i = 1; i < n; i++) {
      int last = s[i] - '0';
      auto last_i2 = [&]() -> type {
        if (i < 2) {
          return 1;
        }
        return *max_element(dp[i - 2].begin(), dp[i - 2].end());
      }();
      bool zero_check = (i + 1 >= n || s[i + 1] != '0');
      if (!zero_check) {
        i++;
      }
      for (int cur = 0; cur < 10; cur++) {
        std::vector<int> candidates = {};
        if (zero_check) {
          if (s[i] == '?' || last == cur) {
            for (int c = 0; c < 10; c++) {
              if (dp[i - 1][c] < 0) {
                continue;
              }
              auto v = (((c == 1 || (c == 2 && cur <= 6))) ? last_i2 : 0) +
                       ((cur != 0) ? dp[i - 1][c] : 0);

              if (v > dp[i][cur]) {
                dp[i][cur] = v;
                candidates = {c};
              } else if (v == dp[i][cur]) {
                candidates.push_back(c);
              }
            }
          } else {
            dp[i][cur] = -1;
          }
          for (auto c : candidates) {
            g[i - 1][c].push_back(cur);
          }
        } else {
          if ((s[i - 1] == '?' || last == cur) && (cur == 1 || cur == 2)) {
            for (int c = 0; c < 10; c++) {
              if (dp[i - 2][c] < 0) {
                continue;
              }
              auto v = dp[i - 2][c];

              if (v > dp[i][cur]) {
                dp[i][cur] = v;
                candidates = {c};
              } else if (v == dp[i][cur]) {
                candidates.push_back(c);
              }
            }
          } else {
            dp[i - 1][cur] = -1;
          }
          for (auto c : candidates) {
            g[i - 2][c].push_back(-cur);
          }
        }
      }
    }

    auto max = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    std::vector<std::vector<i64>> cnt(n, std::vector<i64>(10));
    for (int cur = 0; cur < 10; cur++) {
      if (dp[n - 1][cur] >= max) {
        cnt[n - 1][cur] = 1;
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int cur = 0; cur < 10; cur++) {
        std::sort(g[i][cur].begin(), g[i][cur].end(), std::greater<>());
        if (g[i][cur].size() && g[i][cur][0] < 0) {
          std::sort(g[i][cur].begin(), g[i][cur].end());
        }
        for (auto t : g[i][cur]) {
          int to = i + 1;
          if (t < 0) {
            to = i + 2;
            t = -t;
          }
          auto v = cnt[i][cur] + cnt[to][t];
          cnt[i][cur] = std::min(2 * k, v);
        }
      }
    }

    i64 remain = k;
    int cur = 0;
    std::string res = "";
    for (int i = 0; i < n; i++) {
      i64 sum = 0;
      auto candidates = [&] {
        if (i == 0) {
          return vector{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        }
        return g[i - 1][cur];
      }();
      bool fliped = false;
      for (auto next : candidates) {
        auto to = i;
        if (next < 0) {
          to = i + 1;
          next = -next;
          fliped = true;
        }
        if (sum + cnt[to][next] >= remain) {
          cur = next;
          res += char('0' + next);
          if (fliped) {
            res += '0';
          }
          remain -= sum;
          break;
        }
        sum += cnt[to][next];
      }
    }

    std::cout << "Case #" << case_no << ": ";
    std::cout << res << " " << count(res) << "\n";
  }
}
