#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  int n = 11;
  int T = 10000;
  // vector<int> cnt(n);
  // for (int _ = 0; _ < T; _++) {
  //   int pos = 0;
  //   cnt[pos]++;
  //   while (pos != n - 1) {
  //     if (rng() % 2) {
  //       pos++;
  //     } else {
  //       pos--;
  //     }
  //     if (pos < 0) pos = 1;
  //     if (pos >= n) pos = n - 2;
  //     cnt[pos]++;
  //   }
  // }
  // for (int i = 0; i < n; i++) {
  //   cout << (double(cnt[i]) / T) << "\n";
  // }
  auto get_p = [&](int start) {
    int res = 0;
    for (int _ = 0; _ < T; _++) {
      int pos = start;
      while (true) {
        if (pos == 0 || pos == n - 1) break;
        if (rng() % 2) {
          pos++;
        } else {
          pos--;
        }
        if (pos < 0) pos = 1;
        if (pos >= n) pos = n - 2;
      }
      if (pos == 0) res++;
    }
    return res;
  };
  for (int i = 0; i < n; i++) {
    cout << (double(get_p(i)) / T) << "\n";
  }
}
