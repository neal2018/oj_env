#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
      if (n % i == 0) {
        n += i;
        break;
      }
    }
    k--;
    n += k * 2;
    cout << n << "\n";
  }
}
