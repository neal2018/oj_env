#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll total = accumulate(a.begin(), a.end(), 0ll);
    ll blue = accumulate(a.begin(), a.begin() + (n + 1) / 2, 0ll);
    ll red = total - blue;
    if (n % 2 == 0) {
      red -= a[(n + 1) / 2];
    }
    cout << (red > blue ? "YES\n" : "NO\n");
  }
}
