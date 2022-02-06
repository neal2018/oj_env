#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

constexpr ll inf = 1e18;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  auto f = [&]() {
    ll n, m;
    cin >> n >> m;
    if (m == 1 && n != 1) return -1ll;
    if (m == 1 && n == 1) return 1ll;
    return ((n - m + m - 2) / (m - 1)) * 2 + 1;
  };
  while (T--) cout << f() << "\n";
}
