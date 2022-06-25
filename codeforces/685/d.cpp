#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll d, k;
    cin >> d >> k;
    // k*z*k*z*2 <= d*d
    __int128 z = [&] {
      ll l = 0, r = d;
      while (l < r) {
        __int128 mid = (l + r + 1) / 2;
        if (2 * k * k * mid * mid <= d * d) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      return l;
    }();
    if (k * k * z * z + k * k * (z + 1) * (z + 1) <= d * d) {
      cout << "Ashish\n";
    } else {
      cout << "Utkarsh\n";
    }
  }
}
