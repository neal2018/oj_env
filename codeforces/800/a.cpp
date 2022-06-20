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
    vector<ll> a(n), pre(n + 1);
    for (auto& x : a) cin >> x;
    for (auto i : views::iota(0, n)) pre[i + 1] = pre[i] + a[i];
    cout << ([&] {
      for (auto i : views::iota(1, n + 1)) {
        if (pre[i] < 0) return false;
        if (pre[i] == 0) {
          return all_of(pre.begin() + i, pre.end(), [](int x) { return x == 0; });
        }
      }
      return false;
    }()
                 ? "Yes\n"
                 : "No\n");
  }
}
