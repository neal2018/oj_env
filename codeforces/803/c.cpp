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
    int pos = 0, neg = 0;
    for (auto& x : a) {
      if (x > 0) pos++;
      if (x < 0) neg++;
    }
    if (n < 5) {
      cout << ([&] {
        set st(a.begin(), a.end());
        for (auto i : views::iota(0, n)) {
          for (auto j : views::iota(i + 1, n)) {
            for (auto k : views::iota(j + 1, n)) {
              if (st.count(a[i] + a[j] + a[k]) == 0) return false;
            }
          }
        }
        return true;
      }()
                   ? "YES\n"
                   : "NO\n");
      continue;
    }
    if (pos > 1 || neg > 1 || (pos == 1 && neg == 1 && a[0] + a.back() != 0)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
