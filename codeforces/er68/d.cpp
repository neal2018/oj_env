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
    if (k % 3 != 0) {
      if (n % 3 == 0) {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    } else {
      ll a = n % (k + 1);
      if (a % 3 == 0 && a != k) {
        cout << "Bob\n";
      } else {
        cout << "Alice\n";
      }
    }
  }
}
