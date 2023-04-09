#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector a(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[j][i];
      }
    }
    ll res = 0;
    for (auto& v : a) {
      ll sum = 0, cnt = 0;
      sort(v.rbegin(), v.rend());
      for (auto& x : v) {
        res += sum - cnt * x;
        sum += x, cnt++;
      }
    }
    cout << res << "\n";
  }
}
