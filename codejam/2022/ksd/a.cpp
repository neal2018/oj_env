#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://space.bilibili.com/672328094

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int case_no = 1; case_no <= T; case_no++) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    sort(a.begin(), a.end(), greater<>());
    int sum = 0;
    for (int i = 0; i < m - 1; i++) sum += a[i];
    long double remain = 0;
    if ((n - m + 1) & 1) {
      remain = a[m - 1 + (n - m + 1) / 2];
    } else {
      remain = (long double)(a[m - 1 + (n - m + 1) / 2 - 1] + a[m - 1 + (n - m + 1) / 2]) / 2;
    }
    cout << "Case #" << case_no << ": " << sum + remain << "\n";
  }
}
