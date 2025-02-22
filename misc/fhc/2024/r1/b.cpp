#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int MAX_N = 2e7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> min_primes(MAX_N), primes;
  primes.reserve(1e7);
  for (int i = 2; i < MAX_N; i++) {
    if (!min_primes[i]) min_primes[i] = i, primes.push_back(i);
    for (auto& p : primes) {
      if (p * i >= MAX_N) break;
      min_primes[p * i] = p;
      if (i % p == 0) break;
    }
  }

  std::vector<int> good(MAX_N);
  for (int i = 3; i < MAX_N - 2; i++) {
    if ((min_primes[i] == i) && (min_primes[i + 2] == i + 2)) {
      good[i] = 1;
    }
  }
  std::vector<int> pre(MAX_N + 1);
  for (int i = 0; i < MAX_N; i++) pre[i + 1] = pre[i] + good[i];
  int T;
  std::cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    int n;
    std::cin >> n;
    int has_2 = (n >= 5);
    std::cout << "Case #" << case_no << ": " << (pre[n + 1] - good[n] - good[n - 1] + has_2)
              << "\n";
  }
}
