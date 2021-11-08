#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long
#define ld long double
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n, m, r;
  ld p;
  cin >> T;
  cout << fixed << setprecision(10);
  while (T--) {
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    auto b = a;
    ranges::sort(b);
    int pre = n - 1;
    for (int i = n - 1; i >= 0 && a[i] == b[i]; i--) pre = i - 1;
    ld failure = 1;
    for (int i = 0; i < m; i++) {
      cin >> r >> p;
      if (r > pre) failure *= 1 - p;
    }
    cout << (pre < 0 ? 1 : (1 - failure)) << '\n';
  }
}