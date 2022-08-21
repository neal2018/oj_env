#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

constexpr auto eps = 1e-14;
const auto PI = acos(-1);

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    int n;
    ld R1, R2;
    cin >> n >> R1 >> R2;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    a.push_back(a[0] + 20000);
    ld res = 0, s = 0;
    for (int i = 0; i < n; i++) {
      ld b = (a[i + 1] - a[i]) * PI / 20000;
      res += R2 * R2 * (3 * b * (2 * R1 * R1 + R2 * R2) - 8 * R1 * R2 * sin(b)) / 12;
      res -= R1 * R1 * R1 * R1 * tan(b) / cos(b) / cos(b) / 12;
      s += R2 * R2 * b / 2 - R1 * R1 * tan(b) / 2;
    }
    cout << res / s << "\n";
  }
}
