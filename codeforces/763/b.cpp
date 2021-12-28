#include <bits/stdc++.h>
using namespace std;
// https://space.bilibili.com/672328094
#define ll long long

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T, n;
  cin >> T;
  auto f = [&]() {
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      for (int j = l; j <= r; j++) cnt[j]++;
    }
    function<void(int, int)> solve = [&](int l, int r) {
      if (l == r) {
        cout << l << " " << r << " " << l << "\n";
        return;
      }
      if (r < l) return;
      int mini = l;
      for (int i = l; i <= r; i++) {
        if (cnt[mini] > cnt[i]) {
          mini = i;
        }
      }
      cout << l << " " << r << " " << mini << "\n";
      solve(l, mini - 1), solve(mini + 1, r);
    };
    solve(1, n);
    cout << "\n";
  };
  while (T--) f();
}