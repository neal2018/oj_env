#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  vector<int> res(n, 1e9);

  for (auto&& f : vector<function<int(int)>>{
           {[&](int i) { return i - a[i] + n; }, [&](int i) { return i + a[i]; }}}) {
    vector<int> t(2 * n + 1);
    for (int i = 0; i < n; i++) t[f(i) + 1]++;
    for (int i = 1; i < 2 * n + 1; i++) t[i] += t[i - 1];
    for (int i = 0; i < n; i++) {
      int x = f(i);
      auto check = [&](int mid) {
        return t[min(2 * n - 1, x + mid) + 1] - t[max(0, x - mid)] >= 2;
      };
      int l = 0, r = 2 * n;
      while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      res[i] = min(res[i], r);
    }
  }
  for (auto& x : res) cout << x << " ";
  cout << "\n";
}
