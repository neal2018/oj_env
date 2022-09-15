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
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int res = 0;
    multiset<int> sa(a.begin(), a.end());
    multiset<int> sb(b.begin(), b.end());
    auto to_digit = [](int x) {
      int cnt = 0;
      while (x) {
        x /= 10;
        cnt++;
      }
      return cnt;
    };
    while (sa.size()) {
      auto la = *sa.rbegin();
      auto lb = *sb.rbegin();
      if (la == lb) {
        sa.extract(la);
        sb.extract(lb);
      } else {
        if (la > lb) {
          sa.extract(la);
          sa.insert(to_digit(la));
        } else {
          sb.extract(lb);
          sb.insert(to_digit(lb));
        }
        res++;
      }
    }
    cout << res << "\n";
  }
}
