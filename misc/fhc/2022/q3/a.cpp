#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    cout << "Case #" << case_no << ": ";
    int n;
    cin >> n;
    array<vector<int>, 4> a{vector<int>(n / 4), vector<int>(n / 4), vector<int>(n / 4),
                            vector<int>(n / 4)};
    for (auto& r : a) {
      for (auto& x : r) cin >> x;
      sort(r.begin(), r.end());
    }
    auto check = [&](int mid) {
      for (int i = 0; i < mid; i++) {
        if (max(a[0][i], a[2][i]) > max(a[1][n / 4 - mid + i], a[3][n / 4 - mid + i])) {
          return false;
        }
      }
      return true;
    };
    int l = 0, r = n / 4;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (check(mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << (n / 4 - l) << "\n";
  }
}
