#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,lzcnt,popcnt,abm,mmx,avx,avx2,bmi,bmi2")

#include <iostream>

#define MAXN 2000007

int h[MAXN], w[MAXN], s[MAXN];

void solve() {
  int n, q;
  std::cin >> n >> q;

  for (int i = 0; i < n; i++) {
    std::cin >> h[i] >> w[i];
    s[i] = h[i] * w[i];
  }

  for (int j = 0; j < q; j++) {
    int hs, ws, hb, wb;
    std::cin >> hs >> ws >> hb >> wb;

    wb = wb * 2;
    wb /= 2;

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (hs < h[i] && ws < w[i] && h[i] < hb && w[i] < wb) ans += s[i];
    }
    std::cout << ans << "\n";
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
