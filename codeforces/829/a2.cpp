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
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    auto s = accumulate(a.begin(), a.end(), 0);
    if (s < 0) {
      for (auto& x : a) x = -x;
      s = -s;
    }
    if (s % 2 == 1) {
      cout << "-1\n";
      continue;
    }
    s /= 2;
    vector<int> dp(n), from(n);
    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1];
      int po = (i > 1 ? dp[i - 2] : 0) + a[i];
      if (po > dp[i]) {
        from[i] = 1;
        dp[i] = po;
      }
    }
    auto t = [&] {
      for (int i = 0; i < n; i++) {
        if (dp[i] == s) {
          return i;
        }
      }
      return -1;
    }();
    if (t == -1) {
      cout << "-1\n";
      continue;
    }
    vector<int> sign(n);
    while (t >= 0) {
      if (from[t] == 1) {
        sign[t] = 1, t -= 2;
      } else {
        t -= 1;
      }
    }
    vector<pair<int, int>> out;
    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && sign[j - 1] != sign[j];) j++;
      out.push_back({i, j - 1});
    }
    cout << out.size() << "\n";
    int sum = 0;
    for (auto& [x, y] : out) {
      cout << x + 1 << " " << y + 1 << "\n";
      for (int ii = x; ii <= y; ii++) {
        sum += (a[ii]) * ((ii - x) % 2 ? 1 : -1);
      }
    }
    assert(sum == 0);
  }
}
