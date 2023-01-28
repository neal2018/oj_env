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
    sort(a.begin(), a.end());
    int res = 0;

    while (a.size() && a.back() != 0) {
      int cur = 0;
      while (a.size() && a.back() > cur) cur++, a.pop_back();
      res += cur;
    }

    cout << res << "\n";
  }
}