#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ll T;
  cin >> T;
  for (; T--;) {
    int n, mini = 1e9, maxi = -1e9;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      mini = min(mini, x), maxi = max(maxi, x);
    }
    cout << maxi - mini << '\n';
  }
}