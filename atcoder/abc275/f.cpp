#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 1e9;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  vector<int> dp1(m + 1, inf), dp2(m + 1, inf);  // has, not has
  dp1[0] = 0;
  dp2[0] = 1;
  for (auto& x : a) {
    vector<int> ndp1(m + 1, inf), ndp2(m + 1, inf);
    {  // delete x
      ndp2 = dp2;
      for (int i = 0; i <= m; i++) {
        ndp2[i] = min(ndp2[i], dp1[i] + 1);
      }
    }
    {  // keep x
      for (int i = x; i <= m; i++) {
        ndp1[i] = min(ndp1[i], dp1[i - x]);
        ndp1[i] = min(ndp1[i], dp2[i - x]);
      }
    }
    dp1 = ndp1;
    dp2 = ndp2;
  }
  for (int i = 1; i <= m; i++) {
    auto t = min(dp1[i], dp2[i]);
    cout << (t == inf ? -1 : t) << "\n";
  }
}
