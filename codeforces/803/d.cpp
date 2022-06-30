#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      cout << "? " << l << " " << mid << endl;
      int cnt = 0;
      for (int t = (mid - l) + 1, x; t--;) {
        cin >> x;
        if (l <= x && x <= mid) cnt++;
      }
      if (cnt & 1) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << "! " << l << endl;
  }
}
