#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    vector<tuple<string, int, int>> a(n);
    for (auto& [x, y, z] : a) cin >> x >> y >> z;
    auto b = a;
    sort(a.begin(), a.end(), [&](auto x, auto y) {
      return get<0>(x) != get<0>(y) ? get<0>(x) < get<0>(y) : get<2>(x) < get<2>(y);
    });

    sort(b.begin(), b.end(), [&](auto x, auto y) {
      return get<1>(x) != get<1>(y) ? get<1>(x) < get<1>(y) : get<2>(x) < get<2>(y);
    });
    int res = 0;
    for (int i = 0; i < n; i++) {
      res += (get<2>(a[i]) == get<2>(b[i]));
    }
    cout << res << "\n";
  }
}
