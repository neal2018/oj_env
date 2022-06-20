#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int res = 0;
    for (int left = 0, right = 0, cur = 0; right < n; right++) {
      cur += a[right];
      while (cur > s) {
        cur -= a[left], left++;
      }
      if (cur == s) {
        res = max(res, right - left + 1);
      }
    }
    cout << (res == 0 ? -1 : n - res) << "\n";
  }
}
