
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;
  for (int test_case_no = 1; test_case_no <= T; test_case_no++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end());
    ll res = 0;
    if (n == 5) {
      res = max((a[3] + a[4]) - (a[0] + a[2]), (a[2] + a[4]) - (a[0] + a[1]));
    } else {
      res = (a[n - 2] + a[n - 1]) - (a[0] + a[1]);
    }

    cout << "Case #" << test_case_no << ": " << (res / (long double)2.0) << "\n";
  }
}
